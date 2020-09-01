#include <iostream>
#include <string>

using namespace std;

int main(){
    string min;
    string cur;
    cin >> min;
    for (int i = 0; i < 2; ++i){
        cin >> cur;
        if (cur < min) min = cur;
    }
    cout << min;
    return 0;
}