#include <vector>
using namespace std;
 
vector<int> Reversed(const vector<int>& v){
     vector<int> temp;
     int l = v.size();
     for (int i = l - 1; i >= 0; --i){
        temp.push_back(v[i]);
     }
     return temp;
 }