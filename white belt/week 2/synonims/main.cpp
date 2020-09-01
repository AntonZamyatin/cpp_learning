#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(){
    map<string, set<string>> synonims;
    int n;
    string command;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> command;
        if (command == "ADD"){
            string s1, s2;
            cin >> s1 >> s2;
            synonims[s1].insert(s2);
            synonims[s2].insert(s1);
        }
        if (command == "COUNT"){
            string s;
            cin >> s;
            cout << synonims[s].size() << endl;
        }
        if (command == "CHECK"){
            string s1, s2;
            cin >> s1 >> s2;
            if (synonims[s1].find(s2) != synonims[s1].end()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}