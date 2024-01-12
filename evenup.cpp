#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int lefti = 0;
    while (lefti + 1 < nums.size()) {
        if ((nums[lefti] + nums[lefti+1]) % 2 == 0) {
            nums.erase(nums.begin() + lefti);
            nums.erase(nums.begin() + lefti);
            if (lefti != 0)
                lefti--;
        }
        else
            lefti++;
    }

    cout << nums.size() << "\n";
    return 0;
}