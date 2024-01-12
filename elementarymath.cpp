#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
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
    int n, s = 0, t = 1;
    cin >> n;

    vector<pair<int, int> > nums = vector<pair<int, int> >();
    unordered_map<long long int, int> ans = unordered_map<long long int, int>();
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        nums.push_back(pair<int, int> (x, y));
        if (!ans.count(x+y))
            ans[x+y] = ans.size()+n+2;
        if (!ans.count(x-y))
            ans[x-y] = ans.size()+n+2;
        if (!ans.count((long long int) (x) * (long long int) (y)))
            ans[(long long int) (x) * (long long int) (y)] = ans.size()+n+2;
    }

    int v, n1, n2, n3, nodes = ans.size()+n+2;
    pair<int, int> edge = pair<int, int> (1, 1);
    G = vector<vector<pair<int, int> > >(nodes, vector<pair<int, int> >(nodes, pair<int, int> (0, 0)));
    adj = vector<vector<int> >(nodes, vector<int>(0));
    for (int i = 0; i < n; i++) {
        v = i + 2, x = nums[i].first, y = nums[i].second;
        n1 = ans[x+y], n2 = ans[x-y], n3 = ans[(long long int) (x) * (long long int) (y)];
        G[s][v] = edge;
        G[v][n1] = edge;
        G[v][n2] = edge;
        G[v][n3] = edge;
        adj[s].push_back(v);
        adj[v] = {s, n1, n2, n3};
        adj[n1].push_back(v);
        adj[n2].push_back(v);
        adj[n3].push_back(v);
    }

    for (auto a : ans) {
        v = a.second;
        G[v][t] = edge;
        adj[v].push_back(t);
        adj[t].push_back(v);
    }

    parent = vector<int>(nodes);
    int maxFlow = 0, augFlow;
    while (bfs(s, t, nodes)) {
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

    if (maxFlow < n)
        cout << "impossible\n";
    else {
        for (int i = 0; i < n; i++) {
            v = i + 2, x = nums[i].first, y = nums[i].second;
            n1 = ans[x+y], n2 = ans[x-y], n3 = ans[(long long int) (x) * (long long int) (y)];
            if (!G[v][n1].first)
                cout << x << " + " << y << " = " << x+y << "\n";
            else if (!G[v][n2].first)
                cout << x << " - " << y << " = " << x-y << "\n";
            else if (!G[v][n3].first)
                cout << x << " * " << y << " = " << (long long int) (x) * (long long int) (y) << "\n";
        }
    }
    return 0;
}