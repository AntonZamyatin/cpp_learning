#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct BusesForStopResponse {
  bool no_stop;
  string stop;
  vector<string> buses;
};

struct AllBusesResponse {
  bool no_buses;
  map<string, vector<string>> buses;
};

struct StopsForBusResponse {
  bool no_bus;
  vector<string> st_order;
  map<string, vector<string>> stops;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);
ostream& operator << (ostream& os, const StopsForBusResponse& r);
ostream& operator << (ostream& os, const AllBusesResponse& r);
