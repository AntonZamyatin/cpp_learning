#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string print_vec(vector<int> v){
    ostringstream oss;
    auto it = v.begin();
    while (it != v.end()){
        oss << *it;
        if (it != v.end()-1){
            oss << " ";
        }
        ++it;
    }
    return oss.str();
}

vector<string> permute(vector<int> v){
    vector<string> answ;
    answ.push_back(print_vec(v));
    while(next_permutation(v.begin(), v.end())){
        answ.push_back(print_vec(v));
    }
    answ = vector<string>(answ.rbegin(), answ.rend());
    return answ;
}

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    vector<string> permutes;
    for (int i = 1; i <= n; ++i){
        vec.push_back(i);
    }
    permutes = permute(vec);
    for (string s : permutes){
        cout << s << endl;
    }
}