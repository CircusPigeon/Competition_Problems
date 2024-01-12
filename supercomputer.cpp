#include <iostream>
#include <vector>
using namespace std;

int main () {
    int N, K;
    cin >> N >> K;

    vector<int> nums;
    int tree[2*N];
    for (int i = 0; i < 2*N; i++)
        tree[i] = 0;
    for (int k = 0; k < K; k++) {
        string s;
        cin >> s;
        if (s == "F") {
            int i;
            cin >> i;
            if (tree[N+i-1]) {
                for (int j = N+i-1; j >= 1; j /= 2)
                    tree[j]--;
            }
            else {
                for (int j = N+i-1; j >= 1; j /= 2)
                    tree[j]++;
            }
        }
        if (s == "C") {
            int leftSum = 0, rightSum = 0, l, r;
            cin >> l >> r;
            l = N+l-2;
            r = N+r;
            while (l/2 != r/2) {
                if (l%2 == 0)
                    leftSum += tree[l+1];
                if (r%2 == 1)
                    rightSum += tree[r-1];
                l /= 2;
                r /= 2;
            }
            nums.push_back(leftSum + rightSum);
        }
    }

    for (auto n : nums)
        cout << n << "\n";
    return 0;
}