#ifndef OUTPUT_HPP
#define OUTPUT_HPP

void writeXYZ(std::string Path, const std::vector<Point>& Output) {
    std::ofstream File(Path);
    if (!File.is_open()) {
        std::cout << "Error: Could not open the file.\n";
        return;
    }

    for (const auto& El : Output) {
        File << El.X << " " << El.Y << " " << El.Z << std::endl;
    }

    File.close();
}

#endif //OUTPUT_HPP
