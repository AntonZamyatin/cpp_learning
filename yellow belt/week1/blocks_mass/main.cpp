#include <iostream>

using namespace std;

int main(){
    int n;
    int p;
    cin >> n >> p;
    int w;
    int h;
    int d;
    uint64_t mass = 0;
    int large = 0;
    for (int i = 0; i < n; ++i){
        cin >> w >> h >> d;
        if (mass > mass + static_cast<uint64_t>(p) * w * h * d) ++large;
        mass += static_cast<uint64_t>(p) * w * h * d;
    }
    if (large>0) cout << large;
    cout << mass;
    return 0;
}