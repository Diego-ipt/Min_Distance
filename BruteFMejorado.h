#ifndef BRUTEFMEJORADO_H
#define BRUTEFMEJORADO_H

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include "DyV.h"
#include "BruteF.h"

using namespace std;

//usando el sort de la STL (combina heapsort, quicksort, insertion sort)
/* vector<Point> sort_by_X_coord(const vector<Point>& points) {
    vector<Point> sorted = points;
    sort(sorted.begin(), sorted.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });
    return sorted;
}
 */

//utilizando el merge sort a mano
vector<Point> sort_by_X_coord(const vector<Point>& P) {
    return getSortedPoints(P, 'x');
}

//optimizado trivialmente: ordena los puntos segun coordenada X y en cada iteración compara la diferencia de las distancias de los puntos en eje X, y si supera la distancia minima termina. Esto sirve para no revisar puntos inutiles
double bruteForce_optimized(const vector<Point>& P) {
    double minDist = numeric_limits<double>::max();
    vector<Point> sorted = sort_by_X_coord(P);
    int n = sorted.size();

    //para debug
   /*  Point a;
    Point b; */

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((sorted[j].x - sorted[i].x) >= minDist)
                break;  // aca termina
            double d = distance(sorted[i], sorted[j]);
            if (d < minDist) {
                minDist = d;
               /*  a = sorted[i];
                b = sorted[j]; */
            }
        }
    }

    //cout << "(" << a.x << ", " << a.y << ")" << " (" << b.x << ", " << b.y << ")" << endl;

    return minDist;
}


#endif 