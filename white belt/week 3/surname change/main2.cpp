#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    name_changes[year] = first_name;
    name_changes_years.push_back(year);
    sort(name_changes_years.begin(), name_changes_years.end());
  }
  void ChangeLastName(int year, const string& last_name) {
    surname_changes[year] = last_name;
    surname_changes_years.push_back(year);
    sort(surname_changes_years.begin(), surname_changes_years.end());
  }

  string GetFullName(int year) {
    int n_year = -1;
    int s_year = -1;
    for (int i = 0; i < name_changes_years.size(); ++i){
        if (name_changes_years[i] <= year) n_year = name_changes_years[i];
        if (name_changes_years[i] > year) break;
    }
    for (int i = 0; i < surname_changes_years.size(); ++i){
        if (surname_changes_years[i] <= year) s_year = surname_changes_years[i];
        if (surname_changes_years[i] > year) break;
    }
    if ((n_year != -1) && (s_year != -1)) return name_changes[n_year] + " " + 
                                                 surname_changes[s_year];
    else if ((n_year == -1) && (s_year == -1)) return "Incognito";
    else if (n_year == -1) return surname_changes[s_year] + " with unknown first name";
    else return name_changes[n_year] + " with unknown last name";
  }

  string GetFullNameWithHistory(int year) {
    vector<string> names;
    vector<string> surnames;
    string name;
    string surname;
    string result = "";
    int name_year_pos = -1;
    int surname_year_pos = -1;
    for (int i = 0; i < name_changes_years.size(); ++i){
        if (name_changes_years[i] <= year) name_year_pos = i;
        if (name_changes_years[i] > year) break;
    }

    if (name_year_pos >= 0){
      for (int i = name_year_pos; i >= 0; --i){
        name = name_changes[name_changes_years[i]];
        if (find(names.begin(), names.end(), name) != names.end() - 1){
          names.push_back(name);
        }
      }
    }

    for (int i = 0; i < surname_changes_years.size(); ++i){
        if (surname_changes_years[i] <= year) surname_year_pos = i;
        if (surname_changes_years[i] > year) break;
    }
    
    if (surname_year_pos >= 0){
      for (int i = surname_year_pos; i >= 0; --i){
        surname = surname_changes[surname_changes_years[i]];
        if (find(surnames.begin(), surnames.end(), surname) != surnames.end() - 1){
          surnames.push_back(surname);
        }
      }
    }

    if (names.size() == 0 && surnames.size() == 0) result = "Incognito";
    else if (names.size() == 0) result = GetNames(surnames) + " with unknown first name";
    else if (surnames.size() == 0) result = GetNames(names) + " with unknown last name";
    else result = GetNames(names) + ' ' + GetNames(surnames);

/*
    cout << "==============\n";
    for (auto y : name_changes_years)
      cout << y << " ";
    cout << endl;
    for (auto y : name_changes)
      cout << y.second << " ";
    cout << endl;
    for (auto y : surname_changes_years)
      cout << y << " ";
    cout << endl;
    for (auto y : surname_changes)
      cout << y.second << " ";
    cout << endl;
*/
    return result;
  }

 

private:
  vector<int> name_changes_years;
  vector<int> surname_changes_years;
  map<int, string> name_changes;
  map<int, string> surname_changes;

  string GetNames(vector<string>& names){
    string result = "";
    if (names.size() == 1) return names[0];
    else {
      result = names[0] + " (";
      for (int i = 1; i < names.size() - 1; ++i) result += names[i] + ", ";
      result += names[names.size() - 1] + ')'; 
    }
    return result; 
  }
};


int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}
