#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    bool left[n], right[n];
    int maxL = 0, minR = nums[n-1]+1;
    for (int i = 0; i < n; i++) {
        if (nums[i] >= maxL) {
            maxL = nums[i];
            left[i] = 1;
        }
        else
            left[i] = 0;

        if (nums[n-i-1] < minR) {
            minR = nums[n-i-1];
            right[n-i-1] = 1;
        }
        else
            right[n-i-1] = 0;
    }

    int pivots = 0;
    for (int i = 0; i < n; i++) {
        if (left[i] == 1 && right[i] == 1)
            pivots++;
    }

    cout << pivots << "\n";
    return 0;
}