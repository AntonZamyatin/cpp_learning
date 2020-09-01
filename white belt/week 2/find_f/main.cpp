#include <iostream>
#include <string>
using namespace std;

int main(){
    string s = "";
    cin >> s;
    bool f1 = false;
    for (int i = 0; i < s.length(); ++i){
        if (f1){
            if (s[i] == 'f') {
                cout << i;
                return 0;
            }
        } else {
            if (s[i] == 'f') f1 = true;
        }
    }
    if (f1) cout << -1;
    else cout << -2;
    return 0;
}
