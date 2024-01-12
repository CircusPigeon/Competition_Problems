#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main () {
    string line;
    getline(cin, line);
    int K = stoi(line);

    vector<vector<int> > branches;
    getline(cin, line);
    while (line.compare("-1") != 0) {
        vector<int> branch;
        istringstream is(line);
        int n;
        while (is >> n)
            branch.push_back(n);
        branches.push_back(branch);
        getline(cin, line);
    }

    bool root = false;
    int next = K;
    while (!root) {
        root = true;
        for (int i = 0; i < branches.size(); i++) {
            for (int j = 1; j < branches[i].size(); j++) {
                if (branches[i][j] == next) {
                    root = false;
                    cout << next << " ";
                    next = branches[i][0];
                }
            }
        }
    }
    cout << next << "\n";

    return 0;
}