#include <iostream>
#include <vector>
using namespace std;

int main () {
    int N;
    cin >> N;

    vector<int> swaps;
    int indices[2*N];
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        indices[i] = 0;
        indices[N+n-1] = i;
    }

    int n = 0;
    for (int i = 0; i < N; i++) {
        if (i%2 == 0) {
            n = i/2;
            for (int j = n+1; j < N-n; j++) {
                if (indices[N+j] < indices[N+n])
                    indices[N+j]++;
            }
        }
        else {
            n = N-i/2-1;
            for (int j = N-n; j < n+1; j++) {
                if (indices[N+j] > indices[N+n])
                    indices[N+j]--;
            }
        }
        swaps.push_back(abs(n-indices[N+n]));
        indices[N+n] = n;
    }

    for (auto n : swaps)
        cout << n << "\n";
    return 0;
}