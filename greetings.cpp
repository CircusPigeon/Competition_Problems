#include <iostream>
#include <string>
using namespace std;

int main () {
    string s, e;
    getline(cin, s);
    int len = s.size();
    e = s.substr(1, len - 2);
    cout << "h" + e + e + "y\n";
    return 0;
}