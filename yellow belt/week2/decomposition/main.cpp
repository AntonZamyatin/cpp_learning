#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  string qt;
  is >> qt;
  if (qt=="NEW_BUS"){
      string bus;
      cin >> bus;
      int stop_count;
      cin >> stop_count;
      vector<string> stops(stop_count);
      for (string& stop : stops) {
        cin >> stop;
      }
      q = Query{QueryType::NewBus, bus, " ", stops};
  } else if (qt=="BUSES_FOR_STOP") {
      string stop;
      cin >> stop;
      q = Query{QueryType::BusesForStop, " ", stop, vector<string>{}};
  } else if (qt=="STOPS_FOR_BUS") {
      string bus;
      cin >> bus;
      q = Query{QueryType::StopsForBus, bus, " ", vector<string>{}};
  } else if (qt=="ALL_BUSES") {
      q = Query{QueryType::AllBuses, " ", " ", vector<string>{}};
  }
  return is;
}

struct BusesForStopResponse {
  bool no_stop;
  string stop;
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.no_stop){
      os << "No stop";
  } else {
    bool first = true;
    for (const string& bus: r.buses){
        if (!first) os << ' ';
        os << ' ' << bus;
        first = false;
    }
  }
  return os;
}

struct StopsForBusResponse {
  bool no_bus;
  vector<string> st_order;
  map<string, vector<string>> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  bool first = true;
  if (r.no_bus){
      os << "No bus";
  } else {
    for (auto& stop : r.st_order){
      if (!first) os << endl;
      os << "Stop " << stop << ":";
        for (const string& bus: r.stops.at(stop)){
            os << " " << bus;
        }
      first = false;
    }
  }
  return os;
}

struct AllBusesResponse {
  bool no_buses;
  map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.no_buses) {
        os << "No buses";
    } else {
        for (const auto& bus : r.buses) {
            os << "Bus " << bus.first << ": ";
            for (const string& stop : bus.second) {
                os << stop << " ";
            }
          os << endl;
        }
    }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
      buses_to_stops[bus] = stops;
      for (const string& stop : stops) {
        stops_to_buses[stop].push_back(bus);
      }
      return;
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      if (stops_to_buses.count(stop) == 0) {
        return BusesForStopResponse{true, "No stop", vector<string>{}};
      } else {
        vector<string> buses;
        for (const string& bus : stops_to_buses.at(stop)) {
          buses.push_back(bus);
        }
        return BusesForStopResponse{false, stop, buses};
      }
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    if (buses_to_stops.count(bus) == 0){
        return StopsForBusResponse{true, vector<string>{}, map<string, vector<string>>{}};
    } else {
        map<string, vector<string>> stops;
        vector<string> st_oreder;
        for (const string& stop : buses_to_stops.at(bus)) {
            st_oreder.push_back(stop);
          if (stops_to_buses.at(stop).size() == 1) {
            stops[stop].push_back("no interchange");
          } else {
            for (const string& other_bus : stops_to_buses.at(stop)) {
              if (bus != other_bus) {
                stops[stop].push_back(other_bus);
              }
            }
          }
        }
        return StopsForBusResponse{false, st_oreder, stops};
    }
  }

  AllBusesResponse GetAllBuses() const {
    if (buses_to_stops.empty()){
        return AllBusesResponse{true, map<string, vector<string>>{}};
    } else {
        return AllBusesResponse{false, buses_to_stops};
    }
  }

private:
      map<string, vector<string>> buses_to_stops, stops_to_buses;
};

// РќРµ РјРµРЅСЏСЏ С‚РµР»Р° С„СѓРЅРєС†РёРё main, СЂРµР°Р»РёР·СѓР№С‚Рµ С„СѓРЅРєС†РёРё Рё РєР»Р°СЃСЃС‹ РІС‹С€Рµ

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}