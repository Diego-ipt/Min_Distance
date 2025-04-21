#ifndef BRUTEF_H
#define BRUTEF_H

#include <vector>
#include <cmath>
#include <limits>
using namespace std;

struct Point {
    int x, y;
};

double distance(const Point& p1, const Point& p2) {
    return sqrtf((p1.x - p2.x) * (p1.x - p2.x) +
                 (p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(const vector<Point>& P) {
    double minDist = numeric_limits<double>::max();
    int n = P.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double d = distance(P[i], P[j]);
            if (d < minDist)
                minDist = d;
        }
    }
    return minDist;
}

#endif // BRUTEF_H
