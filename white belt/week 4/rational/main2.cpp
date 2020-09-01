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

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
