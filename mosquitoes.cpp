#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

vector<pair<double, double> > getCircCenters (pair<double, double> p1, pair<double, double> p2, double d) {
    double dist = sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
    if ((p1.first == p2.first && p1.second == p2.second) || dist > d + 0.00001)
        return {};
    double deltX = p2.first - p1.first;
    double deltY = p2.second - p1.second;
    double avgX = (p1.first + p2.first) / 2.0;
    double avgY = (p1.second + p2.second) / 2.0;
    double diff = sqrt(pow(d, 2) - pow(dist, 2)) / 2.0;
    pair<double, double> c1 = pair<double, double> (avgX + diff * deltY / dist, avgY - diff * deltX / dist);
    pair<double, double> c2 = pair<double, double> (avgX - diff * deltY / dist, avgY + diff * deltX / dist);
    return {c1, c2};
}

int main () {
    int n;
    cin >> n;
    int ans[n];
    for (int c = 0; c < n; c++) {
        int m;
        double d;
        cin >> m >> d;
        pair<double, double> mosqs[m];
        for (int i = 0; i < m; i++){
            double x, y;
            cin >> x >> y;
            mosqs[i] = pair<double, double> (x, y);
        }
        int maxCount = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i != j) {
                    vector<pair<double, double> > centers = getCircCenters(mosqs[i], mosqs[j], d);
                    if (centers.size() > 0) {
                        for (auto center : centers) {
                            int count = 0;
                            for (int k = 0; k < m; k++) {
                                double dist = sqrt(pow(mosqs[k].first - center.first, 2) + pow(mosqs[k].second - center.second, 2));
                                if (dist <= d / 2.0 + 0.00001)
                                    count++;
                            }
                            if (count > maxCount)
                                maxCount = count;
                        }
                    }
                }
            }
        }
        ans[c] = maxCount;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";
    return 0;
}