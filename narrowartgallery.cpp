#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > values;
vector<vector<vector<int> > > dp;
int MAX;
int minBlocked(int k, int n);
int recurrence(int k, int n, int c);

int minBlocked(int k, int n) {
    return min(recurrence(k, n, 0), recurrence(k, n, 1));
}

int recurrence(int k, int n, int c) {
    if (k == 0)
        return 0;
    if (n < 0)
        return MAX;
    if (dp[k][n][c] != -1)
        return dp[k][n][c];
    dp[k][n][c] = min(values[n][c] + recurrence(k-1, n-1, c), minBlocked(k, n-1));
    return dp[k][n][c];
}

int main() {
    int N, K;
    cin >> N >> K;

    values = vector<vector<int> >(N, vector<int>(2));
    dp = vector<vector<vector<int> > >(K+1, vector<vector<int> >(N, vector<int>(2)));
    MAX = 100*K;

    int maxValue = 0;
    for (int i = 0; i < N; i++) {
        cin >> values[i][0];
        cin >> values[i][1];
        maxValue += values[i][0] + values[i][1];
    }

    for (int i = 0; i < K+1; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    
    maxValue -= minBlocked(K, N-1);
    cout << maxValue << "\n";
}