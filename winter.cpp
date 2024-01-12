#include <iostream>
#include <string>
using namespace std;

int main () {
    int n, d;
    cin >> n >> d;

    int d_i, years = 0;
    bool earliest = true;
    while (earliest && years < n) {
        cin >> d_i;
        if (d_i <= d)
            earliest = false;
        else
            years++;
    }

    if (earliest)
        cout << "It had never snowed this early!\n";
    else
        cout << "It hadn't snowed this early in " + to_string(years) + " years!\n";
    return 0;
}