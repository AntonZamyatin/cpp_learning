#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> bin;
    cin >> n;
    while (n > 0){
        bin.push_back(n % 2);
        n /= 2;
    }
    for (int i = bin.size() - 1; i >= 0; --i) cout << bin[i];
    cout << endl;
    return 0;
}