#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& dest){
    for (string s : source){
        dest.push_back(s);
    }
    source.clear();
}