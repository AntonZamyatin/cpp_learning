#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(){
    int n;
    string s;
    vector<string> strings;
    cin >> n;
    while (n > 0){
        --n;
        cin >> s;
        strings.push_back(s);
    }
    sort(strings.begin(), strings.end(), [](string s1, string s2){
        transform(s1.begin(), s1.end(), s1.begin(), [](char c){return tolower(c);});
        transform(s2.begin(), s2.end(), s2.begin(), [](char c){return tolower(c);});
        return s1<s2?true:false;
    });
    for(const auto & i : strings) cout << i << ' ';
    cout << endl;
    return 0;
}