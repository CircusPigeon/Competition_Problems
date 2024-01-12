#include <iostream>
using namespace std;

int main () {
    int X, N;
    cin >> X >> N;

    int Mbs = (N+1) * X, Mb;
    for (int i = 0; i < N; i++) {
        cin >> Mb;
        Mbs -= Mb;
    }

    cout << Mbs << "\n";
    return 0;
}