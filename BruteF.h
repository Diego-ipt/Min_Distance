#ifndef BRUTEF_H
#define BRUTEF_H

#include <vector>
#include <cmath>
#include <limits>
using namespace std;

struct Point {
    int x, y;
};

float distance(const Point& p1, const Point& p2) {
    return sqrtf((p1.x - p2.x) * (p1.x - p2.x) +
                 (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(const vector<Point>& P) {
    float minDist = numeric_limits<float>::max();
    int n = P.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            float d = distance(P[i], P[j]);
            if (d < minDist)
                minDist = d;
        }
    }
    return minDist;
}

#endif // BRUTEF_H
