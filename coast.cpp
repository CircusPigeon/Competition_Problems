#include <iostream>
#include <string>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;

    int map[N][M];
    string line;
    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < M; j++)
            map[i][j] = int(line[j]) - 48;
    }

    int coast = 0;
    cout << coast << "\n";
    return 0;
}