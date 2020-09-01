#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;

class Data{
public:

    Data(){}

    Data(const int& year, const int& month, const int& day){
        stringstream error;
        this->year = year;
        if ((month < 1) || (month > 12)) {
            error << "Month value is invalid: " << month; 
            throw invalid_argument(error.str());
        } else this->month = month;
        if ((day < 1) || (day > 31)) {
            error << "Day value is invalid: " << day; 
            throw invalid_argument(error.str());
        } else this->day = day;
    }
    
    int getDay() const {return day;}
    int getMonth() const {return month;}
    int getYear() const {return year;}

private:
    int year;
    int month;
    int day;
};

ostream& operator<<(ostream& stream, const Data& data){
    stream << setw(4) << setfill('0') << data.getYear() << '-'
           << setw(2) << setfill('0') << data.getMonth() << '-'
           << setw(2) << setfill('0') << data.getDay();
    return stream;
}

Data dataFromString(string data_str){
    stringstream stream(data_str);
    int year, month, day;
    char sep1, sep2;
    string err_string = "Wrong date format: " + data_str;
    if ((stream >> year >> sep1 >> month >> sep2 >> day) && 
        (stream.peek() == EOF) &&
        (sep1 == '-') && (sep2 == '-')) 
        return Data(year, month, day);
    else
        throw invalid_argument(err_string);
    
    
}

istream& operator>>(istream& stream, Data& data){
    string data_str;
    stream >> data_str;
    try{ 
        data = dataFromString(data_str);
    }
    catch (invalid_argument& er){
        cout << er.what() << endl;
        exit(0);
    }
    return stream;
}

bool operator<(const Data& first, const Data& second){
    double f_date = first.getYear()*10000 + 
                 first.getMonth()*100 +
                 first.getDay();
    double s_date = second.getYear()*10000 + 
                 second.getMonth()*100 +
                 second.getDay();
    if (f_date < s_date) return true;
    else return false;
}

class Database{
public:
    Database(){};

    void addEvent(Data& data, const string event){
        db[data].insert(event);
    }

    void delEvent(Data& data, const string event){
        if (db[data].find(event) != db[data].end()){
            db[data].erase(event);
            cout << "Deleted successfully" << endl;
        } else {
            cout << "Event not found" << endl;
        }
    }

    void delAllEvents(Data& data){
        int n = db[data].size();
        db[data].clear();
        cout << "Deleted " << n << " events" << endl;
    }

    void find(const Data& data){
        if (db.count(data) > 0){
            for (const auto& event : db[data]){
                cout << event << endl;
            }
        }
    }

    string printAll(){
        stringstream ss;
        for (const auto& data_rec : db){
            for (const auto& event : data_rec.second)
                ss << data_rec.first << ' ' << event << endl;
        }
        return ss.str();
    }

private:
    map<Data, set<string>> db;
};

int main() {
  Database db;
    
  string command;
  while (getline(cin, command)) {
    stringstream ss(command);
    string com;
    ss >> com;
    if (com == "Add"){
        Data data;
        string event_name;
        ss >> data >> event_name;
        db.addEvent(data, event_name);
    } else if (com == "Print"){
        cout << db.printAll();
    } else if (com == "Find"){
        Data data;
        ss >> data;
        db.find(data);
    } else if (com == "Del"){
        Data data;
        string event_name;
        ss >> data >> event_name;
        if (event_name == "") 
            db.delAllEvents(data);
        else 
            db.delEvent(data, event_name);
    } else if (com != ""){
        cout << "Unknown command: " << com << endl;
        return 0;
    }
  }

  return 0;
}