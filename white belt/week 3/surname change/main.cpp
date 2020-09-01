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

private:
  vector<int> name_changes_years;
  vector<int> surname_changes_years;
  map<int, string> name_changes;
  map<int, string> surname_changes;
};


int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}