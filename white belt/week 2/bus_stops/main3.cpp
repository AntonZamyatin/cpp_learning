#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(){
    int q, n;
    int i = 0;
    string s;
    map<set<string>, int> routes;
    cin >> q;
    while (q > 0){
        --q;
        cin >> n;
        set<string> tmp;
        while (n > 0){
            --n;
            cin >> s;
            tmp.insert(s);
        }
        if (routes.find(tmp) != routes.end()) cout << "Already exists for " 
                                                   << routes[tmp] << endl;
        else {++i; routes[tmp] = i; cout << "New bus " << i << endl;}
    }
}