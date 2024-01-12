#include <iostream>
#include <string>
using namespace std;

int main () {
    string s;
    getline(cin, s);
    int n = stoi(s.substr(0, s.find(" ")));
    int p = stol(s.substr(s.find(" ")));
    
    getline(cin, s);
    int nums[n];
    for (int i = 0; i < n - 1; i++) {
        nums[i] = stoi(s.substr(0, s.find(" ")));
        s = s.substr(s.find(" ") + 1);
    }
    nums[n - 1] = stoi(s);

    int max = 0, profit = 0;
    for (int i = 0; i < n; i++) {
        if (profit < 0)
            profit = 0;
        profit += nums[i] - p;
        if (profit > max)
            max = profit;
    }

    cout << max << "\n";
}