#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream input("input.txt");
    ofstream out("output.txt");
    if (input){
        string line;
        while(getline(input, line)){
            out << line << endl;
        }
    }
}