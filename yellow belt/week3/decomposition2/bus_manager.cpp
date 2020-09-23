#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
      buses_to_stops[bus] = stops;
      for (const string& stop : stops) {
        stops_to_buses[stop].push_back(bus);
      }
      return;
  }

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
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

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
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


AllBusesResponse BusManager::GetAllBuses() const {
  if (buses_to_stops.empty()){
      return AllBusesResponse{true, map<string, vector<string>>{}};
  } else {
      return AllBusesResponse{false, buses_to_stops};
  }
}
