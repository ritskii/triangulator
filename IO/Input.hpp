#ifndef INPUT_HPP
#define INPUT_HPP

std::tuple<int, std::vector<Point>, MinMax> readXYZ(const std::string& Path) {
    MinMax MM;
    std::ifstream File(Path);
    std::vector<Point> Result;
    if (!File.is_open()) {
        std::cout << "Error: Could not open the file.\n";
        return {0, Result, MM};
    }

    std::string Line;
    int Vertices = 0;

    while (std::getline(File, Line)) {
        std::stringstream ss(Line);
        Point P;
        ss >> P.X >> P.Y >> P.Z;
        Vertices++;

        if (P.X < MM.MinX) MM.MinX = P.X;
        if (P.Y < MM.MinY) MM.MinY = P.Y;
        if (P.Z < MM.MinZ) MM.MinZ = P.Z;

        if (P.X > MM.MaxX) MM.MaxX = P.X;
        if (P.Y > MM.MaxY) MM.MaxY = P.Y;
        if (P.Z > MM.MaxZ) MM.MaxZ = P.Z;

        Result.emplace_back(P);
    }

    File.close();

    return {Vertices, Result, MM};
}

#endif //INPUT_HPP
