#ifndef DYVMEJORADO_H
#define DYVMEJORADO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "BruteFMejorado.h"
#include "BruteF.h"
#include "DyV.h"

using namespace std;

//se usa sort de STL 
/* vector<Point> getSortedPoints_STL(const vector<Point>& points, char coord) {
    vector<Point> sorted = points;
    if (coord == 'x')
        sort(sorted.begin(), sorted.end(), [](const Point& a, const Point& b) { return a.x < b.x; });
    else if (coord == 'y')
        sort(sorted.begin(), sorted.end(), [](const Point& a, const Point& b) { return a.y < b.y; });
    else
        return points;

    return sorted;
} */


//se minimiza el costo al evitar llamadas sqrt de la distancia euclidiana
//al buscar el minimo en la franja ordenados por el eje Y, se hace un break cuando la distancia entre 2 puntos supera la distancia minima actual
/* double closestPairRec_optimized(const vector<Point>& Px, const vector<Point>& Py) {
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
    double min_dist_pow = min_dist * min_dist;

    //creación de franja
    vector<Point> strip;
    for (const auto& p : Py) {
        if ((p.x - midPoint.x) * (p.x - midPoint.x) < min_dist_pow)
            strip.push_back(p);
    }

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && j <= i + 7; ++j) {
            double d = distance_sin_raiz(strip[i], strip[j]);
            if (d < min_dist_pow) min_dist_pow = d;
        }
    }

    return sqrt(min_dist_pow); 

} */

double closestPairRec_optimized(const vector<Point>& Px, const vector<Point>& Py) {
    int n = Px.size();
    if (n <= 3)
        return bruteForce(Px);

    int mid = n / 2;
    const Point& midPoint = Px[mid];

    vector<Point> Qx, Rx;
    Qx.insert(Qx.end(), Px.begin(), Px.begin() + mid);
    Rx.insert(Rx.end(), Px.begin() + mid, Px.end());

    vector<Point> Qy, Ry;
    Qy.reserve(mid);          // Reserva para evitar realocaciones
    Ry.reserve(n - mid);      // Reserva también aquí

    for (const Point& p : Py) {
        if (p.x <= midPoint.x)
            Qy.push_back(p);
        else
            Ry.push_back(p);
    }

    double left_min_dist = closestPairRec_optimized(Qx, Qy);
    double right_min_dist = closestPairRec_optimized(Rx, Ry);
    double min_dist = min(left_min_dist, right_min_dist);
    double min_dist_pow = min_dist * min_dist;

    vector<Point> strip;
    strip.reserve(n);

    for (const Point& p : Py) {
        if ((p.x - midPoint.x) * (p.x - midPoint.x) < min_dist_pow)
            strip.push_back(p);
    }

    // se limita a 7 vecinos siguientes, puesto que es el numero maximo demostrado matematicamente
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && j <= i + 7; ++j) {
            double dist = distance_sin_raiz(strip[i], strip[j]);
            if (dist < min_dist_pow)
                min_dist_pow = dist;
        }
    }

    return sqrt(min_dist_pow);
}

double closestPair_optimized(vector<Point>& points) {
    if (points.size() < 2) return 0.0;

    //utiliza el merge sort a mano
    vector<Point> Px = getSortedPoints(points, 'x');
    vector<Point> Py = getSortedPoints(points, 'y');
    return closestPairRec_optimized(Px, Py);
}

#endif // DYVMEJORADO_H
