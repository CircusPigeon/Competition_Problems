#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int N, H;
    cin >> N >> H;

    int lower[N/2], upper[N/2];
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            cin >> lower[i/2];
        else
            cin >> upper[(i-1)/2];
    }
    for (int i = 0; i < N/2; i++) {
        lower[i]--;
        upper[i] = H - upper[i];
    }

    sort(lower, lower + N/2, greater<int>());
    sort(upper, upper + N/2);
    int collisions[H];
    for (int i = 0; i < H; i++)
        collisions[i] = 0;

    int height = lower[0];
    for (int i = 0; i < N/2; i++) {
        if (lower[i] != height) {
            collisions[height] += i;
            for (int h = height - 1; h > lower[i]; h--)
                collisions[h] += i;
            height = lower[i];
        }
    }
    for (int h = 0; h <= height; h++)
        collisions[h] += N/2;
    
    height = upper[0];
    for (int i = 0; i < N/2; i++) {
        if (upper[i] != height) {
            collisions[height] += i;
            for (int h = height + 1; h < upper[i]; h++)
                collisions[h] += i;
            height = upper[i];
        }
    }
    for (int h = height; h < H; h++)
        collisions[h] += N/2;

    int min = N, num = 0;
    for (int h = 0; h < H; h++) {
        if (collisions[h] < min)
            min = collisions[h];
    }
    for (int h = 0; h < H; h++) {
        if (collisions[h] == min)
            num++;
    }
        
    cout << min << " " << num << "\n";
    return 0;
}