#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > G[n];
    for (int i = 0; i < n; i++) {
        vector<pair<int, int> > neighbors;
        G[i] = neighbors;
    }
    int a, b, d;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        G[a].push_back(pair<int, int> (b, d));
        G[b].push_back(pair<int, int> (a, d));
    }

    vector<bool> visited(n, false);
    vector<int> next(n, -1);
    vector<int> D(n, INT_MAX);
    priority_queue<pair<int, int> > P;
    D[1] = 0;
    P.push(pair<int, int> (0, 1));

    int v, u;
    while (!P.empty()) {
        v = P.top().second;
        P.pop();
        if (visited[v]) continue;
        visited[v] = true;

        for (int i = 0; i < G[v].size(); i++) {
            u = G[v][i].first;
            d = G[v][i].second;

            if (!visited[u] && D[u] > D[v] + d) {
                D[u] = D[v] + d;
                next[u] = v;
                P.push(pair<int, int> (-D[u], u));
            }
        }
    }

    for (int i = 0; i < n; i++)
        visited[i] = false;
    vector<int> prev(n, -1);
    queue<int> Q;
    Q.push(0);

    while (!Q.empty() && Q.front() != 1) {
        v = Q.front();
        Q.pop();
        if (visited[v]) continue;
        visited[v] = true;

        for (int i = 0; i < G[v].size(); i++) {
            u = G[v][i].first;
            if (!visited[u] && u != next[v]) {
                prev[u] = v;
                Q.push(u);
            }
        }
    }

    if (prev[1] == -1)
        cout << "impossible\n";
    else {
        vector<int> path(1, 1);
        v = 1;
        while (v != 0) {
            path.insert(path.begin(), prev[v]);
            v = prev[v];
        }
        cout << path.size();
        for (int i = 0; i < path.size(); i++)
            cout << " " << path[i];
        cout << "\n";
    }
    return 0;
}