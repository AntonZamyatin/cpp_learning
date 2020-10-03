#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
    deque<string> expression;
    string s1, s2;
    cin >> s1;
    expression.push_back(s1);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> s1;
        cin >> s2;
        expression.push_front("(");
        expression.push_back(")");
        expression.push_back(" "+s1+" "+s2);
    }
    for (string& ss : expression){
        cout << ss;
    }
    cout << endl;
}