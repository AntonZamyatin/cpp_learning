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
    RandomIt left_begin = elements.begin();
    RandomIt left_end = elements.begin() + elements.size() / 2;
    RandomIt right_begin = elements.begin() + elements.size() / 2;
    RandomIt right_end = elements.end();
    MergeSort(left_begin, left_end);
    MergeSort(right_begin, right_end);
    merge(left_begin, left_end, right_begin, right_end, range_begin);
}