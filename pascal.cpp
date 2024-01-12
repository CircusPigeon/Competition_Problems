#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int N;
    cin >> N;

    int counter = 0;
    for (int i = 2; i <= pow(N, 0.5); i++) {
        if (N % i == 0) {
            counter = N - N/i;
            break;
        }
    }

    if (!counter)
        counter = N-1;
    cout << counter << "\n";
    return 0;
}