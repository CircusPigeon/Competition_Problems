#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isSetCover (vector<int> adj[], int subset, int n) {
    vector<bool> visited = vector<bool>(n, false);
    int v = 0, numCovered = 0;

    while (numCovered < n && v < n) {
        int k = 1 << v;
        if (subset & k) {
            if (!visited[v]) {
                visited[v] = true;
                numCovered++;
            }
            for (int i = 0; i < adj[v].size(); i++) {
                int u = adj[v][i];
                if (!visited[u]) {
                    visited[u] = true;
                    numCovered++;
                }
            }
        }
        v++;
    }

    if (numCovered == n)
        return true;
    return false;
}

int minCover (vector<int> adj[], int subset, int i, int k, int n) {
    if (i - k > n)
        return n;
    if (i == n) {
        if (isSetCover(adj, subset, n))
            return k;
        return n;
    }
    else
        return min(minCover(adj, subset, i+1, k, n), minCover(adj, subset | 1 << i, i+1, k+1, n));
}

int main () {
    int N;
    cin >> N;

    int minAds[N];
    for (int c = 0; c < N; c++) {
        int n;
        cin >> n;
        vector<int> adj[n];
        for (int v = 0; v < n; v++) {
            int k;
            cin >> k;
            for (int i = 0; i < k; i++) {
                int u;
                cin >> u;
                adj[v].push_back(u-1);
            }
        }

        minAds[c] = minCover(adj, 0, 0, 0, n);
    }

    for (int c = 0; c < N; c++)
        cout << minAds[c] << "\n";
    return 0;
}