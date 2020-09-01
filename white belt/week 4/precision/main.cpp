#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    ifstream input("input.txt");
    if (input){
        double num;
        while(input >> num){
            cout << fixed << setprecision(3) << num << endl;
        }
    }
}