#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

int main () {
    int x1, x2, x3, y1, y2, y3, N;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> N;

    pair<int, int> apples[N];
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        apples[i] = pair<int, int> (x, y);
    }

    double area = (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0;
    if (area < 0) {
        swap(x1, x3);
        swap(y1, y3);
    }
    area = abs(area);

    int numApples = 0;
    for (int i = 0; i < N; i++) {
        if ((x2-x1)*(apples[i].second-y1)-(y2-y1)*(apples[i].first-x1) >= 0 &&
            (x3-x2)*(apples[i].second-y2)-(y3-y2)*(apples[i].first-x2) >= 0 &&
            (x1-x3)*(apples[i].second-y3)-(y1-y3)*(apples[i].first-x3) >= 0)
            numApples++;
    }

    cout << fixed << setprecision(1) << area << "\n";
    cout << numApples << "\n";
    return 0;
}