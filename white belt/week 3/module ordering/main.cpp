#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    vector<int> arr;
    cin >> n;
    while (n > 0){
        --n;
        cin >> k;
        arr.push_back(k);
    }
    sort(arr.begin(), arr.end(), [](int x, int y) {return abs(x) < abs(y) ? true : false;});
    for(const auto & i : arr){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}