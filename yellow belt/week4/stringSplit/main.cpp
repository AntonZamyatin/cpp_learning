#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> SplitIntoWords(const string& s){
    vector<string> v;
    auto st_pos = 0;
    auto end_pos = 0;
    do{   
        end_pos = s.find(' ', st_pos);
        if (end_pos == -1) {
            v.push_back(string(s.begin() + st_pos, s.begin() + s.length()));
            break;
        }
        v.push_back(string(s.begin() + st_pos, s.begin() + end_pos));
        st_pos = end_pos+1;
    } while (end_pos != -1);
    return v;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}
