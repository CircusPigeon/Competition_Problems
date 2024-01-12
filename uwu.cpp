#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    // make grid all u's
    bool grid[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            grid[i][j] = 0;
    }

    // add max size checkerboard of w's
    int k = min(int (sqrt(2*m)), n);
    int numWs = 0;
    if (k > max(2, n-2)) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if ((i+j) % 2 == 1) {
                    grid[i][j] = 1;
                    numWs++;
                }
            }
        }
    }
    else if (k >= 3) {
        for (int i = 1; i < k+1; i++) {
            for (int j = 1; j < k+1; j++) {
                if ((i+j) % 2 == 0) {
                    grid[i][j] = 1;
                    numWs++;
                }
            }
        }
    }

    // add in remaining w's using greedy approach
    while (numWs < m) {
        int maxUwu = -5;
        pair<int, int> maxPos;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {                
                    int numUwu = 0;
                    if (i-1 >= 0 && i+1 < n && grid[i-1][j] == 0 && grid[i+1][j] == 0)
                        numUwu++;
                    if (j-1 >= 0 && j+1 < n && grid[i][j-1] == 0 && grid[i][j+1] == 0)
                        numUwu++;
                    if (i-2 >= 0 && grid[i-1][j] == 1 && grid[i-2][j] == 0)
                        numUwu--;
                    if (i+2 < n && grid[i+1][j] == 1 && grid[i+2][j] == 0)
                        numUwu--;
                    if (j-2 >= 0 && grid[i][j-1] == 1 && grid[i][j-2] == 0)
                        numUwu--;
                    if (j+2 < n && grid[i][j+1] == 1 && grid[i][j+2] == 0)
                        numUwu--;
                    if (numUwu > maxUwu) {
                        maxUwu = numUwu;
                        maxPos = pair<int, int>(i, j);
                    }
                }
            }
        }
        grid[maxPos.first][maxPos.second] = 1;
        numWs++;
    }

    // print output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j])
                cout << "w";
            else
                cout << "u";
        }
        cout << "\n";
    }
    return 0;
}