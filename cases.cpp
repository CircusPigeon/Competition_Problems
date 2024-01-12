#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int seed = rand();
 
int main () {
    int n = rand() % 100000 + 1;
    int m = rand() % 100000 + 1;
    int k = rand() % 100000 + 1;
    int D = rand() % 1000000000 + 1;

    freopen("input.txt", "w", stdout);
    cout << n << " " << m << " " << k << " " << D << "\n";

    for (int i = 0; i < n; i++) {
        int a = rand() % 1000000000 + 1;
        cout << a << " ";
    }
    cout << "\n";

    for (int i = 0; i < m; i++) {
        int b = rand() % 1000000000 + 1;
        cout << b << " ";
    }
    cout << "\n";

    for (int i = 0; i < k; i++) {
        int c = rand() % 1000000000 + 1;
        cout << c << " ";
    }
    cout << "\n";
    
    return 0;
}