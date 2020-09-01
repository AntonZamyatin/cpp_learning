#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> CharMap(const string& s){
    map<char, int> result;
    for (const char& ch : s){
        result[ch]++;
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    string w1, w2;
    while (n > 0){
        --n;
        cin >> w1 >> w2;
        if (w1.length() != w2.length()) cout << "NO" << endl;
        else {
            if (CharMap(w1) == CharMap(w2)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}