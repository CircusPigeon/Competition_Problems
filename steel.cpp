#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<vector<int> > > combs;
int maxCombs = pow(10, 9) + 7;

int DP (int s, int v, int g) {
    if (combs[s][v][g] != -1)
        return combs[s][v][g];

    // base cases
    if (s == 0 && v == 0) {
        combs[s][v][g] = 0;
        return 0;
    }
    if (s == 0) {
        if ((v == 1 && g == 1) || (v > 1 && g == 0)) {
            combs[s][v][g] = 1;
            return 1;
        }
        combs[s][v][g] = 0;
        return 0;
    }
    if (v == 0) {
        if ((s % 2 == 1 && g == 0) || (s % 2 == 0 && g == 1)) {
            combs[s][v][g] = 1;
            return 1;
        }
        combs[s][v][g] = 0;
        return 0;
    }

    if (g == 1) {
        combs[s][v][g] = DP(s-1, v, 0) % maxCombs;
        return combs[s][v][g];
    }
    combs[s][v][g] = (DP(s-1, v, 1) + DP(s, v-1, 1) + DP(s, v-1, 0)) % maxCombs;
    return combs[s][v][g];
}

int main () {
    int s, v, g;
    cin >> s >> v >> g;

    combs = vector<vector<vector<int> > >(s+1, vector<vector<int> >(v+1, vector<int>(2, -1)));
    int numCombs = DP(s, v, g);

    cout << numCombs << "\n";
    return 0;
}