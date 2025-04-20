#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include "BruteF.h"

using namespace std;

//Funciones auxiliar para ordenar los puntos

vector<Point> mergeSorted(const vector<Point>& leftVec, const vector<Point>& rightVec, char coord) {
    vector<Point> result;
    int i = 0, j = 0;

    while (i < leftVec.size() && j < rightVec.size()) {
        bool condition;
        if (coord == 'x')
            condition = leftVec[i].x <= rightVec[j].x;
        else
            condition = leftVec[i].y <= rightVec[j].y;

        if (condition)
            result.push_back(leftVec[i++]);
        else
            result.push_back(rightVec[j++]);
    }

    while (i < leftVec.size())
        result.push_back(leftVec[i++]);
    while (j < rightVec.size())
        result.push_back(rightVec[j++]);

    return result;
}

vector<Point> mergeSortCopy(const vector<Point>& points, char coord) {
    if (points.size() <= 1)
        return points;

    int mid = points.size() / 2;
    vector<Point> left(points.begin(), points.begin() + mid);
    vector<Point> right(points.begin() + mid, points.end());

    vector<Point> sortedLeft = mergeSortCopy(left, coord);
    vector<Point> sortedRight = mergeSortCopy(right, coord);

    return mergeSorted(sortedLeft, sortedRight, coord);
}

// Función principal que puedes usar
vector<Point> getSortedPoints(const vector<Point>& points, char coord) {
    if (coord != 'x' && coord != 'y') return points; // Validación simple
    return mergeSortCopy(points, coord);
}



//Loop principal de la funcion DyV

float closestPairRec(const vector<Point>& Px, const vector<Point>& Py) {
    int n = Px.size();
    if (n <= 3)
        return bruteForce(Px);

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

    float delta1 = closestPairRec(Qx, Qy);
    float delta2 = closestPairRec(Rx, Ry);
    float delta = min(delta1, delta2);

    // Puntos cercanos a la línea de división (dentro de delta)
    vector<Point> strip;
    for (const auto& p : Py) {
        if (abs(p.x - midPoint.x) < delta)
            strip.push_back(p);
    }

    // Comparar hasta los siguientes 11 vecinos
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && j <= i + 11; ++j) {
            float d = distance(strip[i], strip[j]);
            if (d < delta)
                delta = d;
        }
    }

    return delta;
}

float closestPair(vector<Point>& points) {
    if (points.size() < 2) return 0.0;

    vector<Point> Px = getSortedPoints(points, 'x');
    vector<Point> Py = getSortedPoints(points, 'y');

    return closestPairRec(Px, Py);
}



#endif // DYV_H
