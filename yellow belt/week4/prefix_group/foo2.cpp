#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix){
        pair<RandomIt, RandomIt> answ;
        answ.first = lower_bound(range_begin, range_end, prefix, 
            [](const string& s, const string& p) {string ss(s.begin(), s.begin() + p.size()); return ss < p;});
        answ.second = upper_bound(range_begin, range_end, prefix, 
            [](const string& p, const string& s) {string ss(s.begin(), s.begin() + p.size()); return ss > p;});
        return answ;
    }