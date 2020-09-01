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
    if (denominator == 0){
        throw invalid_argument("");
    }
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
    if (second.Numerator() == 0){
        throw domain_error("zero_div");
    }
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
    Rational a, b;
    char operation;
    try {
        cin >> a;
        cin >> operation;
        cin >> b;

        if (operation == '+') cout << a + b;
        if (operation == '-') cout << a - b;
        if (operation == '*') cout << a * b;
        if (operation == '/') cout << a / b;
    } catch (invalid_argument&) {
        cout << "Invalid argument" << endl;
    } catch (domain_error& de){
        cout << "Division by zero";
    }
    return 0;
}