#include <iostream>
#include <string>
#include <deque>

using namespace std;

int get_priotity(string& s){
    if (s == "*" || s == "/") return 1;
    else return 0;
}

int main(){
    deque<string> expression;
    string s1, s2;
    cin >> s1;
    expression.push_back(s1);
    int n;
    int prev = 0;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> s1;
        cin >> s2;
        if (i!=0 && get_priotity(s1) > prev){
            expression.push_front("(");
            expression.push_back(")");
        }
        expression.push_back(" "+s1+" "+s2);
        prev =  get_priotity(s1);
    }
    for (string& ss : expression){
        cout << ss;
    }
    cout << endl;
}