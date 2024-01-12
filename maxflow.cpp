#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int> > > G;
vector<vector<int> > adj;
vector<int> parent;

bool bfs (int s, int t, int n) {
    vector<bool> visited = vector<bool>(n, false);
    visited[s] = true;
    queue<int> Q;
    Q.push(s);
 
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
 
        for (int v : adj[u]) {
            if (!visited[v] && G[u][v].first) {
                parent[v] = u;
                if (v == t)
                    return true;

                visited[v] = true;
                Q.push(v);
            }
        }
    }
    return false;
}

int main () {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    G = vector<vector<pair<int, int> > >(n, vector<pair<int, int> >(n, pair<int, int> (0, 0)));
    adj = vector<vector<int> >(n, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        G[u][v] = pair<int, int> (c, c);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parent = vector<int>(n);
    int maxFlow = 0, augFlow;
    while (bfs(s, t, n)) {
        augFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            if (G[u][v].first < augFlow)
                augFlow = G[u][v].first;
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            G[u][v].first -= augFlow;
            G[v][u].first += augFlow;
        }
        maxFlow += augFlow;
    }

    vector<vector<int> > edges;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (G[u][v].second - G[u][v].first > 0)
                edges.push_back({u, v, G[u][v].second - G[u][v].first});
        }
    }

    cout << n << " " << maxFlow << " " << edges.size() << "\n";
    for (vector<int> e : edges)
        cout << e[0] << " " << e[1] << " " << e[2] << "\n";
    return 0;
}