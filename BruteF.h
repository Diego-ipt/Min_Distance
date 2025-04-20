#ifndef BRUTEF_H
#define BRUTEF_H

#include <iostream>
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

  /*   Point a;
    Point b;
 */
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double d = distance(P[i], P[j]);
            if (d < minDist) {
                minDist = d;
               /*  a = P[i];
                b = P[j]; */
            }
        }

    }
    //cout << "(" << a.x << ", " << a.y << ")" << " (" << b.x << ", " << b.y << ")" << endl;

    return minDist;
}

#endif // BRUTEF_H
