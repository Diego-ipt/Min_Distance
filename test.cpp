
#include "BruteF.h"
#include "DyV.h"
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

    // Test with different problem sizes
    for (int numPoints : {5, 10, 50, 100, 500}) {
        vector<Point> points = generateRandomPoints(numPoints, 1000);

        double bruteForceResult = bruteForce(points);
        double dyvResult = closestPair(points);

        // Allow a small tolerance for doubleing-point comparisons
        assert(abs(bruteForceResult - dyvResult) < 1e-6);

        cout << "Test passed for " << numPoints << " points." << endl;
    }
}

int main() {
    testClosestPair();
    cout << "All tests passed!" << endl;
    return 0;
}