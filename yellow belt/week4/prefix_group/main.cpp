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
int main() {
  const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
  
  const auto mo_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  const auto mt_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
      (mt_result.second - begin(sorted_strings)) << endl;
  
  const auto na_result =
      FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
      (na_result.second - begin(sorted_strings)) << endl;
  
  return 0;
}
