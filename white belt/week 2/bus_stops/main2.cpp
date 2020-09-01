#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n, k;
    map<int,vector<string>> routes;
    vector<string> temp;
    string s;
    int route_num = 1;
    bool exist = false;

    cin >> n;
    while (n>0){
        exist = false;
        --n;
        temp.clear();
        cin >> k;
        for (int i = 0; i < k; ++i){
            cin >> s;
            temp.push_back(s);
        }
        for (const auto& item : routes){
            if (item.second == temp){
                cout << "Already exists for " << item.first << endl;
                exist = true;
                break;
            }
        }
        if (exist) continue;
        routes[route_num] = temp;
        cout << "New bus " << route_num << endl;
        ++route_num;
    }
    return 0;
}