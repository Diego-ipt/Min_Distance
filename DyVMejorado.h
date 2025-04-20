#ifndef DYVMEJORADO_H
#define DYVMEJORADO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "BruteF.h"

using namespace std;

// Solo para comparaciones internas
double distance_sin_raiz(const Point& p1, const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

//se usa sort de STL con nlogn
vector<Point> getSortedPoints_STL(const vector<Point>& points, char coord) {
    vector<Point> sorted = points;
    if (coord == 'x')
        sort(sorted.begin(), sorted.end(), [](const Point& a, const Point& b) { return a.x < b.x; });
    else if (coord == 'y')
        sort(sorted.begin(), sorted.end(), [](const Point& a, const Point& b) { return a.y < b.y; });
    else
        return points;

    return sorted;
}


//se minimiza el costo al evitar llamadas sqrt de la distancia euclidiana
//al buscar el minimo en la franja ordenados por el eje Y, se hace un break cuando la distancia entre 2 puntos supera la distancia minima actual
//el sort es de la STL, no personalizado
double closestPairRec_optimized(const vector<Point>& Px, const vector<Point>& Py) {
    int n = Px.size();
    if (n <= 3)
        return bruteForce(Px);  // Devuelve la distancia real (euclidiana)

    int mid = n / 2;
    Point midPoint = Px[mid];

    vector<Point> Qx(Px.begin(), Px.begin() + mid);
    vector<Point> Rx(Px.begin() + mid, Px.end());

    vector<Point> Qy, Ry;
    for (const auto& p : Py) {
        if (p.x <= midPoint.x)
            Qy.push_back(p);
        else
            Ry.push_back(p);
    }

    double left_min_dist = closestPairRec_optimized(Qx, Qy);
    double right_min_dist = closestPairRec_optimized(Rx, Ry);
    double min_dist = min(left_min_dist, right_min_dist);
    double min_dist_sq = min_dist * min_dist;

    //creación de franja
    vector<Point> strip;
    for (const auto& p : Py) {
        if ((p.x - midPoint.x) * (p.x - midPoint.x) < min_dist_sq)
            strip.push_back(p);
    }

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size(); ++j) {
            if ((strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) >= min_dist_sq)
                break;
            double dSq = distance_sin_raiz(strip[i], strip[j]);
            if (dSq < min_dist_sq)
                min_dist_sq = dSq;
        }
    }

    return sqrt(min_dist_sq); 

}

double closestPair_optimized(vector<Point>& points) {
    if (points.size() < 2) return 0.0;
    vector<Point> Px = getSortedPoints_STL(points, 'x');
    vector<Point> Py = getSortedPoints_STL(points, 'y');
    return closestPairRec_optimized(Px, Py);
}

#endif // DYVMEJORADO_H
