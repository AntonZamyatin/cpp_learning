#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

int64_t avrg(const vector<int64_t>& v){
    int64_t answ=0;
    for (int i=0; i<static_cast<int>(v.size()); ++i){
        answ += v.at(i);
    }
    answ /= static_cast<int>(v.size());
    return answ;
}

int main(){
    int n;
    cin >> n;
    if (n == 0){
        cout << 0 << endl;
    }
    vector<int64_t> days(n);
    for (int i = 0; i<n; ++i){
        cin >> days[i];
    }
    int64_t avg = avrg(days);
    vector<int> over_avg;
    for (int i = 0; i<n; ++i){
        if (days[i] > avg){
            over_avg.push_back(i);
        }
    }
    cout << over_avg.size();
    for (int i = 0; i < static_cast<int>(over_avg.size()); ++i){
        cout << ' ' << over_avg[i];
    }
    cout << endl;
    return 0;
}