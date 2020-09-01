#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string command;
    int arg;
    vector<bool> queue(0);
    int count = 0;

    while (n != 0){
        n--;
        cin >> command;
        if (command == "WORRY"){
            cin >> arg;
            queue[arg] = true;
        }
        if (command == "QUIET"){
            cin >> arg;
            queue[arg] = false;
        }
        if (command == "COME"){
            cin >> arg;
            queue.resize(queue.size() + arg);
        }
        if (command == "WORRY_COUNT"){
            for (bool person : queue){
                if (person) count++;
            }
            cout << count << endl;
            count = 0;
        }
    }
    return 0;
}