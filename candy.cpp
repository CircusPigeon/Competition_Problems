#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int euclidean (int x, int y) {
    int x_i = x, y_i = y, a0 = 0, a1 = 1, b0 = 1, b1 = 0;

    while (y_i != 0) {
        int q = x_i / y_i, r = x_i % y_i;
        int c = a0 - a1 * q, d = b0 - b1 * q;
        x_i = y_i, y_i = r;
        a0 = a1, b0 = b1;
        a1 = c, b1 = d;
    }

    return (a0 + x) % x;
}

int main () {
    int t;
    cin >> t;

    vector<string> answers;
    for (int i = 0; i < t; i++) {
        int K, C;
        cin >> K >> C;

        if (C == 1)
            answers.push_back(to_string(K+1));
        else if (K == 1)
            answers.push_back("1");
        else if (gcd(K, C) != 1)
            answers.push_back("IMPOSSIBLE");
        else
            answers.push_back(to_string(euclidean(K, C)));
    }

    for (string ans : answers)
        cout << ans << "\n";
    return 0;
}