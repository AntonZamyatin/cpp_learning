#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <random>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

/*int gcd(const int& a, const int& b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}*/


void defaultConstructorTest()
{
    Rational R;
    Assert(R.Numerator() == 0, "numerator");
    Assert(R.Denominator() == 1, "denominator");
}

void rationalRulesTest()
{
    mt19937 gen;
    uniform_int_distribution<> unif(-10, 10);
    for (int i = 0; i < 100; ++i)
    {
        int n = unif(gen);
        int d = unif(gen);
        if (d == 0)
            continue;
        if ((n * d) > 0)
        {
            Rational R(n, d);
            Assert(R.Numerator() > 0, "positive numerator");
            Assert(R.Denominator() > 0, "positive denominator");
            Assert(gcd(R.Numerator(), R.Denominator()) == 1, "two positive gcd");
        }
        else if ((n * d) < 0)
        {
            Rational R(n, d);
            Assert(R.Numerator() < 0, "negative numerator");
            Assert(R.Denominator() > 0, "positive denominator");
            Assert(gcd(-R.Numerator(), R.Denominator()) == 1, "one negative gcd");
        }
        else if (n == 0 && d != 0)
        {
            Rational R(n, d);
            Assert(R.Numerator() == 0, "numerator 0");
            Assert(R.Denominator() == 1, "denominator 1");
        }
        else
            continue;
    }
}



int main() {
    TestRunner runner;
    runner.RunTest(defaultConstructorTest, "default constructor");
    runner.RunTest(rationalRulesTest, "rules test");
    return 0;
}