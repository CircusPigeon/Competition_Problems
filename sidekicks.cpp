#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int query (int gems[], int n, int l, int r) {
    int lsum = 0, rsum = 0;
    l = n+l-2;
    r = n+r;
    while (l/2 != r/2) {
        if (l%2 == 0)
            lsum += gems[l+1];
        if (r%2 == 1)
            rsum += gems[r-1];
        l /= 2;
        r /= 2;
    }
    return lsum+rsum;
}

int main () {
    int N, Q;
    cin >> N >> Q;

    int h = ceil(log2(N+2)), n = pow(2, h);
    int gems[6][2*n];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2*n; j++)
            gems[i][j] = 0;
    }
    long long int values[6];
    for (int i = 0; i < 6; i++)
        cin >> values[i];

    string types;
    cin >> types;
    for (int i = 0; i < N; i++) {
        int p = stoi(types.substr(i, 1));
        gems[p-1][n+i] = 1;
    }
    for (int i = 0; i < 6; i++) {
        for (int j = n-1; j >= 1; j--)
            gems[i][j] = gems[i][2*j] + gems[i][2*j+1];
    }

    vector<long long int> sums;
    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, p;
            cin >> k >> p;
            for (int i = 0; i < 6; i++) {
                if (gems[i][n+k-1]) {
                    for (int j = n+k-1; j >= 1; j /= 2) {
                        gems[i][j]--;
                        gems[p-1][j]++;
                    }
                }
            }
        }
        if (t == 2) {
            int p, v;
            cin >> p >> v;
            values[p-1] = v;
        }
        if (t == 3) {
            int l, r;
            cin >> l >> r;
            long long int sum = 0;
            for (int i = 0; i < 6; i++)
                sum += query(gems[i], n, l, r) * values[i];
            sums.push_back(sum);
        }
    }

    for (auto sum : sums)
        cout << sum << "\n";
    return 0;
}