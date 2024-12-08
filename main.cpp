#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>

struct Point {
    float X, Y, Z;
    float NX, NY, NZ;
    Point(float X, float Y, float Z) : X(X), Y(Y), Z(Z),
                                       NX(NX), NY(NY), NZ(NZ) {}

    Point() : X(0.0f), Y(0.0f), Z(0.0f), NX(0.0f), NY(0.0f), NZ(0.0f) {}

    void print() {
        std::cout << "Points: \n"
        << "X: " << X << " Y: " << Y << " Z: " << Z
        << "\nNormals: \n"
        << "NX: " << NX << " NY: " << NY << " NZ: " << NZ << "\n\n";
    }
};

#include "IO/Reader.hpp"
#include "DataStructure/Octree.hpp"

int main() {
    std::vector<Point> PCloud = readXyz("../data/scatter.xyz");

    Octree Tree(Point(-1.1, -1.1, -1.1), Point(1.1, 1.1, 1.1), PCloud);



    return 0;
}
