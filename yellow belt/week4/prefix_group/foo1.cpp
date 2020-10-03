#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix){
        pair<RandomIt, RandomIt> answ;
        answ.first = lower_bound(range_begin, range_end, prefix, [](const string& s, const char& p) {return s[0] < p;});
        answ.second = upper_bound(range_begin, range_end, prefix, [](const char& p, const string& s) {return s[0] > p;});
        return answ;
    }