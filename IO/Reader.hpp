#ifndef READER_HPP
#define READER_HPP


std::vector<Point> readXyz(const std::string& Path) {
    std::ifstream File(Path);
    std::vector<Point> Result;

    if (!File.is_open()) {
        std::cout << "Error: Could not open the file.\n";
        return Result;
    }

    std::string Line;


    while (std::getline(File, Line)) {
        std::stringstream ss(Line);
        Point P;
        ss >> P.X >> P.Y >> P.Z >> P.NX >> P.NY >> P.NZ;
        Result.emplace_back(P);
    }

    File.close();

    return Result;
}


#endif //READER_HPP
