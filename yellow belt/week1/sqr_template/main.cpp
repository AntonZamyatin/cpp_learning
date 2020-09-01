#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template <typename T> T Sqr(const T& x);
template <typename T> vector<T> Sqr(const vector<T>& x);
template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& x);
template <typename First, typename Second> map<First, Second> Sqr(const map<First, Second>& x);

template <typename T>
T Sqr(const T& x){
    return x * x;
}

template <typename T>
vector<T> Sqr(const vector<T>& v){
    vector<T> answ;
    for (auto& i: v){
        answ.push_back(Sqr(i));
    }
    return answ;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p){
    return make_pair(Sqr(p.first), Sqr(p.second));
}

template <typename First, typename Second>
map<First, Second> Sqr(const map<First, Second>& m){
    map<First, Second> answ;
    for (auto& i : m){
        answ[i.first] = Sqr(i.second);
    }
    return answ;
}
int main(){
        // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
      cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}