#include <iostream>
#include <vector>
using namespace std;

void PrintVec(vector<int> v){
    if (v.size() == 0) return;
    if (v.size() == 1) {
        cout << v[0];
    } else {
        cout << v[0];
        for (int i = 1; i < v.size(); ++i){
            cout << ' ' << v[i];
        }
    }
    cout << endl;
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> days_temp(n);
    vector<int> high_t_days;
    int sum = 0;
    int mean = 0;
    for (int& day : days_temp){
        cin >> day;
        sum += day;
    }
    mean = sum / n;
    for (int i = 0; i < days_temp.size(); ++i){
        if (days_temp[i] > mean){
            high_t_days.push_back(i);
        }
    }
    cout << high_t_days.size() << endl;
    PrintVec(high_t_days);
    return 0;
}