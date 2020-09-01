#include <map>
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

bool operator<(const Region& lhs, const Region& rhs){
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
    tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions){
    int res = 0;
    map<Region,int> region_count;
    for (const auto& reg : regions){
        res=max(res, ++region_count[reg]);
    }
    return res;
}
