#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a,b,c,x1,x2,d;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) return 0;
        else {
            x1 = -c / b;
            cout << x1;
            return 0;
        }
    } else {
        d = b*b - 4*a*c;
        if (d < 0) return 0;
        else if (d == 0) {
            x1 = -b / (2*a);
            cout << x1;
            return 0;
        } else {
            x1 = (-b + sqrt(d))/(2*a);
            x2 = (-b - sqrt(d))/(2*a);
            cout << x1 << ' ' << x2;
            return 0;
        }
    }
}
