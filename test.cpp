
#include "BruteF.h"
#include "DyV.h"
#include "DyVMejorado.h"
#include "BruteFMejorado.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate random points
vector<Point> generateRandomPoints(int numPoints, int maxCoord) {
    vector<Point> points;
    for (int i = 0; i < numPoints; ++i) {
        points.push_back({rand() % maxCoord, rand() % maxCoord});
    }
    return points;
}

void testClosestPair() {
    srand(static_cast<unsigned>(time(0)));

    /* vector<Point> points = {
        {81, 53}, {16, 78}, {11, 83}, {33, 14}, {5, 66},
        {53, 43}, {4, 17}, {63, 57}, {71, 82}, {12, 41},
        {4, 18}, {15, 61}, {43, 10}, {30, 49}, {85, 81},
        {30, 54}, {52, 1}, {87, 8}, {62, 52}, {21, 18},
        {88, 24}, {38, 86}, {57, 68}, {75, 58}, {80, 87},
        {59, 59}, {86, 76}, {27, 92}, {24, 63}, {77, 56},
        {72, 40}, {1, 67}, {47, 20}, {64, 52}, {12, 72},
        {60, 36}, {48, 39}, {30, 69}, {78, 58}, {16, 86},
        {71, 58}, {83, 13}, {67, 87}, {96, 34}, {48, 32},
        {99, 85}, {85, 99}, {52, 66}, {81, 83}, {77, 7},
        {42, 51}, {38, 12}, {40, 65}, {99, 18}, {7, 78},
        {14, 88}, {86, 50}, {2, 17}, {59, 18}, {74, 9},
        {72, 79}, {17, 79}, {41, 95}, {29, 78}, {40, 29},
        {42, 73}, {80, 7}, {46, 82}, {97, 28}, {98, 22},
        {27, 17}, {13, 92}, {52, 38}, {97, 86}, {98, 70},
        {64, 36}, {20, 84}, {10, 72}, {48, 80}, {46, 57},
        {52, 58}, {84, 44}, {9, 31}, {64, 88}, {27, 42},
        {96, 8}, {49, 36}, {45, 88}, {67, 67}, {92, 70},
        {87, 82}, {85, 11}, {12, 75}, {45, 39}, {46, 37},
        {35, 53}, {67, 0}, {75, 2}, {87, 80}, {19, 82}
    };
     */
    vector<Point> points = {
        {12, 34}, {87, 23}, {45, 67}, {10, 90}, {75, 80},
        {30, 55}, {60, 20}, {5, 5}, {95, 99}, {50, 40}
    };

    double dyvMejorado = closestPair_optimized(points);
    double dyvResult = closestPair(points);
    double bruteF_opt = bruteForce_optimized(points);
    double bruteF = bruteForce(points);

    cout << "BruteF mejorado: " << bruteF_opt << endl;
    cout << "BruteF: " << bruteF << endl;

    cout << "Dyv mejorado: " << dyvMejorado << endl;
    cout << "Dyv: " << dyvResult << endl;

    // Allow a small tolerance for doubleing-point comparisons
    assert(abs(dyvMejorado - dyvResult) < 1e-6);

    cout << "Test passed for " << points.size() << " points." << endl;
}

int main() {
    testClosestPair();
    cout << "All tests passed!" << endl;
    return 0;
}