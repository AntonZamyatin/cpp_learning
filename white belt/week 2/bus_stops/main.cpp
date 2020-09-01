#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void PrintVec(const vector<string>& v){
    if (v.size() == 0) return;
    if (v.size() == 1) cout << v[0];
    else {
        cout << v[0];
        for (int i = 1; i < v.size(); ++i)
            cout << ' ' << v[i];
    }
}

int main(){
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    vector<string> temp;
    string command, bus, stop;
    int s_count, n;
    cin >> n;

    while (n > 0){
        --n;
        cin >> command;
        if (command == "NEW_BUS"){
            cin >> bus >> s_count;
            for (int i = 0; i < s_count; ++i){
                cin >> stop;
                buses[bus].push_back(stop);
                stops[stop].push_back(bus);
            }
        }
        if (command == "BUSES_FOR_STOP"){
            cin >> stop;
            if (stops.find(stop) == end(stops)) cout << "No stop";
            else PrintVec(stops[stop]);
            cout << endl;
        }
        if (command == "STOPS_FOR_BUS"){
            cin >> bus;
            if (buses.find(bus) == end(buses)){
                cout << "No bus" << endl;
                continue;
            }
            for (const string& stop : buses[bus]){
                temp.clear();
                cout << "Stop " << stop << ": ";
                for (const string& b : stops[stop]){
                    if (bus != b) temp.push_back(b);
                }
                if (temp.size() == 0) cout << "no interchange";
                else PrintVec(temp);
                cout << endl;
            }
        }
        if (command == "ALL_BUSES"){
            if (buses.size() == 0) cout << "No buses" << endl;
            else {
                for (const auto& item : buses){
                    cout << "Bus " << item.first << ": ";
                    PrintVec(buses[item.first]);
                    cout << endl;
                }
            }
        }
    }
    return 0;
}