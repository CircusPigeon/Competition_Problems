#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binSearch (vector<int> nums, int l, int h, int v) {
    while (l <= h) {
        int m = l + (h-l)/2;
        if (nums[m] >= v && (m == 0 || nums[m-1] < v))
            return m;
        if (nums[m] >= v)
            h = m-1;
        if (nums[m] < v)
            l = m+1;
    }

    return nums.size();
}

int main () {
    int N, D;
    cin >> N >> D;

    vector<int> A = vector<int>(N), B = vector<int>(N), C = vector<int>(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    for (int i = 0; i < N; i++)
        cin >> C[i];
    sort(C.begin(), C.end());

    int a, b, x, f, b1, b2, count = 0;
    for (int i = 0; i < N; i++) {
        a = A[i];
        for (int j = 0; j < N; j++) {
            b = B[j];
            x = a ^ b;
            if (a > b)
                f = x ^ (a / b) ^ (x / b) ^ (x / a);
            else
                f = x ^ (b / a) ^ (x / a) ^ (x / b);
            b1 = binSearch(C, 0, N-1, f);
            if (b1 < N) {
                b2 = binSearch(C, 0, N-1, f+D);
                if (b2 > b1)
                    count += b2-b1;
            }
        }
    }

    cout << count << "\n";
    return 0;
}