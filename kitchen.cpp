#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main () {
    int r, s, m, d, n;
    cin >> r >> s >> m >> d >> n;

    int brands[r];
    for (int i = 0; i < r; i++)
        cin >> brands[i];

    vector<int> dishes[s+m+d];
    int k;
    for (int i = 0; i < s+m+d; i++) {
        cin >> k;
        vector<int> dish(k, 0);
        for (int j = 0; j < k; j++) {
            cin >> dish[j];
            dish[j]--;
        }
        dishes[i] = dish;
    }

    map<int, set<int> > hash;
    int i1, i2;
    for (int i = 0; i < n; i++) {
        cin >> i1 >> i2;
        if (i1 > i2)
            swap(i1, i2);
        i1--;
        i2--;
        if (!hash.count(i1)) {
            set<int> conflicts;
            conflicts.insert(i2);
            hash[i1] = conflicts;
        }
        else
            hash[i1].insert(i2);
    }

    bool over = false;
    int used[r];
    int ingred;
    unsigned long long combs, prev;
    unsigned long long total = 0, overflow = 1000000000000000000;
    for (int i = 0; i < s; i++) {
        for (int j = s; j < s+m; j++) {
            for (int k = s+m; k < s+m+d; k++) {
                if (!over && (!hash.count(i) || hash[i].find(j) == hash[i].end()) && (!hash.count(i) || hash[i].find(k) == hash[i].end()) 
                && (!hash.count(j) || hash[j].find(k) == hash[j].end())) {
                    for (int l = 0; l < r; l++)
                        used[l] = 0;
                    combs = 1;
                    for (int l = 0; l < dishes[i].size(); l++) {
                        ingred = dishes[i][l];
                        prev = combs;
                        combs *= brands[ingred];
                        if (prev != combs / brands[ingred])
                            over = true;
                        used[ingred] = 1;
                    }
                    for (int l = 0; l < dishes[j].size(); l++) {
                        ingred = dishes[j][l];
                        if (!used[ingred]) {
                            prev = combs;
                            combs *= brands[ingred];
                            if (prev != combs / brands[ingred])
                                over = true;
                            used[ingred] = 1;
                        }
                    }
                    for (int l = 0; l < dishes[k].size(); l++) {
                        ingred = dishes[k][l];
                        if (!used[ingred]) {
                            prev = combs;
                            combs *= brands[ingred];
                            if (prev != combs / brands[ingred])
                                over = true;
                        }
                    }
                    total += combs;
                    if (total > overflow)
                        over = true;
                }
            }
        }
    }

    if (!over)
        cout << total << "\n";
    else
        cout << "too many\n";
    return 0;
}