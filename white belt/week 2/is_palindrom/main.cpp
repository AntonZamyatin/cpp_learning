#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string s){
    int l = s.length();
    int m = l / 2;
    for (int i = 0; i < m; ++i){
        if (s[i] != s[l - 1 - i]) return false;
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> outv;
    for (string word : words){
        if (IsPalindrom(word) && word.length() >= minLength)
            outv.push_back(word);
    }
    return outv;
}