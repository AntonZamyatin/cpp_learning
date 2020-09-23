#pragma once
#include <vector>
#include <set>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	vector<T> v;
	for (auto it = elements.begin(); it != elements.end(); ++it) {
		if (*it > border) {
			v.push_back(*it);
		}
	}
	return v;
}