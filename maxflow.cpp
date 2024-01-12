#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

vector<vector<int> > G;
vector<vector<int> > adj;
vector<int> flows;

void bfs (int a, int b, int n) {
    vector<bool> visited = vector<bool>(n, false);
    visited[a] = true;
    queue<int> Q;
    Q.push(a);
 
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
 
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                flows[v] = min(flows[u], G[u][i]);
                if (v == b)
                    return;

                visited[v] = true;
                Q.push(v);
            }
        }
    }
    return;
}
 
int main () {
    int n, m;
    cin >> n >> m;
    
    G = vector<vector<int> >(n, vector<int>(0));
    adj = vector<vector<int> >(n, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(w);
        G[v].push_back(w);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    vector<int> maxFlows = vector<int>(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        flows = vector<int>(n, INT_MAX);
        bfs(a, b, n);
        int maxFlow = flows[b];
        maxFlows[i] = maxFlow;
    }

    for (int i = 0; i < q; i++)
        cout << maxFlows[i] << "\n";
    return 0;
}