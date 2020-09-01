#include <iostream>
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

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}