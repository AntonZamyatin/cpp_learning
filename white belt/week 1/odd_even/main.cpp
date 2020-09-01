#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    if (a % 2 != 0) a++;
    if (b % 2 !=0) b--;
    if (a <= b) cout << a;
    a += 2;
    for (int i = a; i <=b; i += 2) cout << ' ' << i;
    return 0;
}