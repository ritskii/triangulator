#include <array>
#include <cmath>
#include <float.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
struct Point {
    float X, Y, Z;
    Point(float X, float Y, float Z) : X(X), Y(Y), Z(Z) {}

    Point() : X(0.0f), Y(0.0f), Z(0.0f) {}

    void print() {
        std::cout << "Points: \n"
        << "X: " << X << " Y: " << Y << " Z: " << Z << "\n\n";
    }
};

struct MinMax {
    float MinX, MinY, MinZ;
    float MaxX, MaxY, MaxZ;

    MinMax()
        : MinX(FLT_MAX), MinY(FLT_MAX), MinZ(FLT_MAX),
          MaxX(-FLT_MAX), MaxY(-FLT_MAX), MaxZ(-FLT_MAX) {}
};
#include "IO/Output.hpp"
#include "DataStructures/VoxelGrid.hpp"
#include "DataStructures/Octree.hpp"
#include "IO/Input.hpp"

int main() {
    auto [Num, PCloud, MM] = readXYZ("../data/table.xyz");
    VoxelGrid Grid(PCloud, MM);
    std::vector<Point> Result = Grid.filter();
    writeXYZ("../data/result.xyz", Result);

    return 0;
}
