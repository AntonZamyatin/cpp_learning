#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void PrintString(ifstream& input, int& m){
    int tmp;
    for (int j = 0; j < m - 1; ++j){
            input >> tmp;
            cout << setw(10) << tmp << " ";
            input.ignore(1);
        }
        input >> tmp;
        cout << setw(10) << tmp;
}

int main(){
    int n, m;
    ifstream input("input.txt");
    input >> n >> m;
    int tmp = 0;
    for (int i = 1; i < n; ++i){
        PrintString(input, m);
        cout << endl;
    }
    PrintString(input, m);
}