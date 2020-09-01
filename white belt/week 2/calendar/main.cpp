#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> calendar(31);
    int n, n_arg;
    int mon = 0;
    string command, s_arg;
    cin >> n;
    while (n > 0){
        n--;
        cin >> command;
        if (command == "ADD"){
            cin >> n_arg >> s_arg;
            calendar[n_arg - 1].push_back(s_arg);
            // cout << "iserting " << s_arg << " to " << n_arg << endl;
        }
        if (command == "NEXT"){
            mon = (mon + 1) % 12;
            // cout << mon << " month, " << months[mon] << " days" << endl;
            if (months[mon] >= calendar.size()){
                calendar.resize(months[mon]);
            } else {
                for (int i = months[mon]; i < calendar.size(); ++i){
                    calendar[months[mon]-1].insert(end(calendar[months[mon]-1]), begin(calendar[i]), end(calendar[i]));
                }
                calendar.resize(months[mon]);
            }
        }
        if (command == "DUMP"){
            cin >> n_arg;
            n_arg--;
            cout << calendar[n_arg].size();
            for (string occup : calendar[n_arg])
                cout << ' ' << occup;
            cout << endl;
        }
        /*
        for (auto day : calendar){
            cout << day.size() << " ";
        }
        cout << endl;
        */
    }
    return 0;
}