#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<pair<int, int> > > pricings;
vector<vector<int> > DP;
int W, maxChoice;

int T (int w, int n) {
    if (w > W)
        return 0;
    if (DP[w][n] != -1)
        return DP[w][n];

    int maxRevenue = -1, revenue;
    for (int i = 0; i < pricings[w].size(); i++) {
        int price = pricings[w].at(i).first;
        int tickets = pricings[w].at(i).second;

        if (tickets <= n)
            revenue = price * tickets + T(w+1, n-tickets);
        else
            revenue = price * n + T(w+1, 0);

        if (w == 0 && (revenue > maxRevenue || (revenue == maxRevenue && price < maxChoice)))
            maxChoice = price;
        if (revenue > maxRevenue)
            maxRevenue = revenue;
    }

    DP[w][n] = maxRevenue;
    return DP[w][n];
}

int main () {
    int N;
    cin >> N >> W;

    pricings = vector<vector<pair<int, int> > >(W+1);
    int K;
    for (int i = 0; i <= W; i++) {
        cin >> K;
        int prices[K], num[K];
        for (int j = 0; j < K; j++)
            cin >> prices[j];
        for (int j = 0; j < K; j++)
            cin >> num[j];
        vector<pair<int, int> > pairs;
        for (int j = 0; j < K; j++)
            pairs.push_back(pair<int, int> (prices[j], num[j]));
        pricings[i] = pairs;
    }

    DP = vector<vector<int> >(W+1, vector<int>(N+1));
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= N; j++)
            DP[i][j] = -1;
    }

    int maxRevenue = T(0, N);
    cout << maxRevenue << "\n";
    cout << maxChoice << "\n";
    return 0;
}