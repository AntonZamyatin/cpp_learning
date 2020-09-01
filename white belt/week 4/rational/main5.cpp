#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int gcd(const int& a, const int& b){
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

class Rational {
public:
  Rational(){
    numerator = 0;
    denominator = 1;
  }
  Rational(int numerator, int denominator){
      if (numerator == 0){
          this->numerator = 0;
          this->denominator = 1;
      }
      else if (denominator < 0){
          SolveFraction(-numerator, -denominator);
      } else {
          SolveFraction(numerator, denominator);
      }
  }

  void SolveFraction(const int& numerator, const int& denominator){
      int g = gcd(abs(numerator), abs(denominator));
      this-> numerator = numerator / g;
      this->denominator = denominator / g;
  }
  int Numerator() const{
      return numerator;
  }
  int Denominator() const{
      return denominator;
  }

private:
    int numerator;
    int denominator;
};

bool operator==(const Rational& first, const Rational& second){
    if ((first.Numerator() == second.Numerator()) && (first.Denominator() == second.Denominator())) return true;
    else return false;
}

Rational operator+(const Rational& first, const Rational& second){
    int common_denominator = first.Denominator() * second.Denominator();
    int new_numerator = (first.Numerator()*second.Denominator() + second.Numerator() * first.Denominator());
    Rational answ(new_numerator, common_denominator);
    return answ;
}

Rational operator-(const Rational& first, const Rational& second){
    int common_denominator = first.Denominator() * second.Denominator();
    int new_numerator = (first.Numerator()*second.Denominator() - second.Numerator() * first.Denominator());
    Rational answ(new_numerator, common_denominator);
    return answ;
}

Rational operator*(const Rational& first, const Rational& second){
    Rational answ(first.Numerator()*second.Numerator(), 
                  first.Denominator()*second.Denominator());
    return answ;
}

Rational operator/(const Rational& first, const Rational& second){
    Rational answ(first.Numerator()*second.Denominator(), 
                  first.Denominator()*second.Numerator());
    return answ;
}


ostream& operator<<(ostream& stream, const Rational& r){
    stream << r.Numerator() << '/' << r.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& r){
    int numerator;
    int denominator;
    char ch = '_';
    if (stream){
        stream >> numerator;
        stream >> ch;
        stream >> denominator;
    }
    if (ch == '/') r = Rational(numerator, denominator);
    return stream;
}

bool operator<(const Rational& first, const Rational second){
    if (first.Numerator()*second.Denominator() < second.Numerator()*first.Denominator()) 
        return true;
    else return false;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}