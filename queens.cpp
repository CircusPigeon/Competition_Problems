#include <iostream>
#include <vector>
using namespace std;

int iterSols (vector<vector<int> >& board, vector<int>& usedRows, vector<int>& usedPosDiags, vector<int>& usedNegDiags, int j, int N) {
    if (j == N)
        return 1;

    int numSol = 0;
    for (int i = 0; i < N; i++) {
        if(board[i][j] && !usedRows[i] && !usedPosDiags[N+(i-j)] && !usedNegDiags[i+j]) {
            usedRows[i] = 1;
            usedPosDiags[N+(i-j)] = 1;
            usedNegDiags[i+j] = 1;
            numSol += iterSols(board, usedRows, usedPosDiags, usedNegDiags, j+1, N);

            usedRows[i] = 0;
            usedPosDiags[N+(i-j)] = 0;
            usedNegDiags[i+j] = 0;
        }
    }
    return numSol;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> numSols;
    while (N != 0) {
        vector<vector<int> > board = vector<vector<int> >(N, vector<int>(N, 1));
        vector<int> usedRows = vector<int>(N, 0), usedPosDiags = vector<int>(2*N, 0), usedNegDiags = vector<int>(2*N, 0);
        for(int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            board[x][y] = 0;
        }

        int numSol = iterSols(board, usedRows, usedPosDiags, usedNegDiags, 0, N);
        numSols.push_back(numSol);
        cin >> N >> M;
    }

    for (int numSol : numSols)
        cout << numSol << "\n";
    return 0;
}