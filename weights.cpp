#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> weights;
    int row1[n], row2[n], w;
    for (int i = 0; i < n; i++) {
        cin >> w;
        row1[i] = w;
        weights.push_back(w);
    }
    for (int i = 0; i < n; i++) {
        cin >> w;
        row2[i] = w;
        weights.push_back(w);
    }

    sort(weights.begin(), weights.end(), greater<int>());
    bool found1, found2;
    int max, i, j = 0;
    while (i < 2*n && weights[i] > max) {
        found1 = false;
        found2 = false;
        w = weights[i];
        j = 0;
        while (j < n && !found2) {
            if (row1[j] == w) {
                if (!found1)
                    found1 = true;
                else if (!found2)
                    found2 = true;
            }
            else if (found1 && row1[j] < w && row1[j] > max)
                max = row1[j];
            j++;
        }
        if (found1 && !found2 && w > max)
            max = w;
        j = 0;
        while (j < n && !found1 && !found2) {
            if (row2[j] == w) {
                if (!found1)
                    found1 = true;
                else if (!found2)
                    found2 = true;
            }
            else if (found1 && row2[j] < w && row2[j] > max)
                max = row2[j];
            j++;
        }
        i+=2;
    }

    cout << max << "\n";
    return 0;
}