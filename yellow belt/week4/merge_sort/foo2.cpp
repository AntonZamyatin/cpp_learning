#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if ((range_end - range_begin) < 2){
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    vector<typename RandomIt::value_type> temp;
    RandomIt left_begin = range_begin;
    RandomIt left_end = range_begin + elements.size() / 3;
    RandomIt right_begin = range_begin + elements.size() / 3;
    RandomIt right_end = range_begin + elements.size() * 2 / 3;
    RandomIt last_begin = range_begin + elements.size() * 2 / 3;
    RandomIt last_end = range_end;
    MergeSort(left_begin, left_end);
    MergeSort(right_begin, right_end);
    MergeSort(last_begin, last_end);
    merge(left_begin, left_end, right_begin, right_end, back_inserter(temp));
    merge(temp.begin(), temp.end(), last_begin, last_end, range_begin);
}