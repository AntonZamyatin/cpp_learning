#include <iostream>
using namespace std;

unsigned int gcd(unsigned int a, unsigned int b){
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    if (a < b) return gcd(a, b % a);
    else return gcd(b, a % b);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}