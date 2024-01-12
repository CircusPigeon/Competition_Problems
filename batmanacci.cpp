#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
    string s;
    getline(cin, s);
    int n = stoi(s.substr(0, s.find(" "))) - 1;
    long k = stol(s.substr(s.find(" "))) - 1;

    vector<long long> fibs;
    fibs.push_back(1);
    fibs.push_back(1);
    int i = 1;
    while (fibs.at(i) + fibs.at(i - 1) <= k) {
        fibs.push_back(fibs.at(i) + fibs.at(i - 1));
        i++;
    }

    while (k >= 2) {
        if (n - 2 > fibs.size() - 1)
            n -= 2;
        else if (k < fibs.at(n - 2))
            n -= 2;
        else {
            k -= fibs.at(n - 2);
            n -= 1;
        }
    }

    string result;
    if (n % 2 == k) 
        result = "N";
    else
        result = "A";

    cout << result << "\n";
    return 0;
}