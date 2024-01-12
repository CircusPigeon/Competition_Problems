#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main () {
    int C, P, X, L;
    cin >> C >> P >> X >> L;

    unordered_map<int, unordered_set<int> > links;
    int A, B;
    for (int i = 0; i < P; i++) {
        cin >> A >> B;
        if (!links.count(A)) {
            unordered_set<int> partners;
            partners.insert(B);
            links[A] = partners;
        }
        else
            links[A].insert(B);
        if (!links.count(B)) {
            unordered_set<int> partners;
            partners.insert(A);
            links[B] = partners;
        }
        else
            links[B].insert(A);
    }

    int numPartners[C];
    for (int i = 0; i < C; i++)
        numPartners[i] = links[i+1].size();

    bool leave = false;
    if (L == X)
        leave = true;
    queue<int> Q;
    Q.push(L);
    while (!Q.empty() && !leave) {
        int l = Q.front();
        Q.pop();
        for (int c : links[l]) {
            links[c].erase(l);
            if (links[c].size() <= numPartners[c-1] / 2) {
                Q.push(c);
                if (c == X)
                    leave = true;
            }
        }
        links.erase(l);
    }

    if (leave)
        cout << "leave\n";
    else
        cout << "stay\n";
    return 0;
}