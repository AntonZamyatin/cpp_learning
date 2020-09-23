#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void PrintVectorPart(vector<int> v) {
	auto it = find_if(v.begin(), v.end(), [](const int& el) {return el < 0; });
	for (auto i = v.begin(); i < it; ++i) {
		cout << *i << " ";
	}
}