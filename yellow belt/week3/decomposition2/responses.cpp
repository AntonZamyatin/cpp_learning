#include "responses.h"

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