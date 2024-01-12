#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main () {
    //freopen("input.txt", "r", stdin);
    int n, m, k, D;
    cin >> n >> m >> k >> D;
 
    vector<int> strengths1 = vector<int>(n), strengths2 = vector<int>(m), extra = vector<int>(k);  
    for (int i = 0; i < n; i++)
        cin >> strengths1[i];
    for (int i = 0; i < m; i++)
        cin >> strengths2[i];
    for (int i = 0; i < k; i++)
        cin >> extra[i];
    
    sort(strengths1.begin(), strengths1.end(), greater<int>());
    sort(strengths2.begin(), strengths2.end(), greater<int>());
    sort(extra.begin(), extra.end(), greater<int>());
 
    int numMoves = 0, eugI = 0, evgI = 0, artyI = 0;
    while (numMoves != -1 && evgI < m) {
        if (eugI < n && strengths1[eugI] >= strengths2[evgI] + D) {
            numMoves++;
            eugI++;
        }
        else if (artyI < k && extra[artyI] >= strengths2[evgI] + D) {
            numMoves += 2;
            artyI++;
        }
        else
            numMoves = -1;
        evgI++;
    }
 
    cout << numMoves << "\n";
    return 0;
}