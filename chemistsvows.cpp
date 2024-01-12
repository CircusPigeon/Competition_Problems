#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main () {
    unordered_set<char> symbs1 = {'h', 'b', 'c', 'n', 'o', 'f', 'p', 's', 'k', 'v', 'y', 'i', 'w', 'u'};
    unordered_set<string> symbs2 = {
        "he", "li", "be", "ne", "na", "mg", "al", "si", "cl", "ar", "ca", "sc", 
        "ti", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", 
        "br", "kr", "rb", "sr", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", 
        "cd", "in", "sn", "sb", "te", "xe", "cs", "ba", "la", "ce", "pr", "nd", 
        "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "hf", 
        "ta", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", 
        "rn", "fr", "ra", "ac", "th", "pa", "np", "pu", "am", "cm", "bk", "cf", 
        "es", "fm", "md", "no", "lr", "rf", "db", "sg", "bh", "hs", "mt", "ds", 
        "rg", "cn", "fl", "lv"
    };
    int T;
    cin >> T;

    string words[T];
    for (int i = 0; i < T; i++)
        cin >> words[i];

    string w;
    bool valid[T];
    for (int i = 0; i < T; i++) {
        w = words[i];
        valid[i] = 0;
        bool DP[w.length()+1];
        DP[0] = 1;
        for (int j = 1; j <= w.length(); j++)
            DP[j] = 0;
        for (int j = 0; j < w.length(); j++) {
            if (DP[j]) {
                if (symbs1.find(w.at(j)) != symbs1.end())
                    DP[j+1] = 1;
                if (symbs2.find(w.substr(j, 2)) != symbs2.end())
                    DP[j+2] = 1;
            }
        }
        if (DP[w.length()] == 1)
            valid[i] = 1;
    }
    
    for (int i = 0; i < T; i++) {
        if (valid[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}