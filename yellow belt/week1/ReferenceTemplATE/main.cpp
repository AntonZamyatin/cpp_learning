#include <iostream>
#include <map>

using namespace std;

template <typename First, typename Second>
Second& GetRefStrict(map<First, Second>& m, const First& key){
    if (m.count(key))
        return m[key];
    else
        throw runtime_error("no such key");
}

int main(){
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}