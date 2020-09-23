#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVectorPart(vector<int> v){
	auto it = find_if(v.begin(), v.end(), [](const int& el) {return el < 0; });
	for (auto i = v.begin(); i < it; ++i) {
		cout << *i << " ";
	}
}

int main() {
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	cout << endl;
	return 0;
}