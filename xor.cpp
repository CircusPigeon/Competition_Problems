#include <iostream>
using namespace std;

int powTwoMod (long long int n, int p) {
    if (n == 0)
        return 1;
    if (n == 1)
        return 2 % p;
    int r = powTwoMod(n/2, p);
    if (n % 2 == 0)
        return (r*r) % p;
    return (2*r*r) % p;
}

int main () {
    long long int n, k;
    int p;
    cin >> n >> k >> p;

    int r1 = powTwoMod(n, p-1);
    r1 = (((r1-n) % (p-1)) + (p-1)) % (p-1);
    int r2 = powTwoMod(r1, p);

    if (k == 0)
        r2--;
    cout << r2 << "\n";
    return 0;
}