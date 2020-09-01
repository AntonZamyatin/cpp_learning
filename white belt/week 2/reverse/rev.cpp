 #include <vector>
using namespace std;
 
 void Reverse(vector<int>& v){
     vector<int> temp;
     int l = v.size();
     for (int i = l - 1; i >= 0; --i){
        temp.push_back(v[i]);
     }
     v = temp;
 }