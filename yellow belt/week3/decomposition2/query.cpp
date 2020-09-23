#include "query.h"

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