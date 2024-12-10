#ifndef VOXELGRID_HPP
#define VOXELGRID_HPP

class VoxelGrid {
private:
    std::vector<std::vector<std::vector<std::vector<Point>>>> Grid;
    MinMax MM;
    float LeafSize;
    int GridSizeX, GridSizeY, GridSizeZ;

public:

    VoxelGrid(std::vector<Point> Cloud, MinMax MM, float LeafSize = 0.01) : LeafSize(LeafSize), MM(MM) {
        GridSizeX = static_cast<int>(std::ceil((MM.MaxX - MM.MinX) / LeafSize));
        GridSizeY = static_cast<int>(std::ceil((MM.MaxY - MM.MinY) / LeafSize));
        GridSizeZ = static_cast<int>(std::ceil((MM.MaxZ - MM.MinZ) / LeafSize));

        Grid.resize(GridSizeX, std::vector<std::vector<std::vector<Point>>>(GridSizeY,
            std::vector<std::vector<Point>>(GridSizeZ)));

        for (const auto& Element : Cloud) {
            int VoxelX = static_cast<int>((Element.X - MM.MinX) / LeafSize);
            int VoxelY = static_cast<int>((Element.Y - MM.MinY) / LeafSize);
            int VoxelZ = static_cast<int>((Element.Z - MM.MinZ) / LeafSize);

            VoxelX = std::min(VoxelX, GridSizeX - 1);
            VoxelY = std::min(VoxelY, GridSizeY - 1);
            VoxelZ = std::min(VoxelZ, GridSizeZ - 1);

            Grid[VoxelX][VoxelY][VoxelZ].push_back(Element);
        }
    }

    std::vector<Point> filter() {
        std::vector<Point> Cloud;
        for (int X = 0; X < GridSizeX; ++X) {
            for (int Y = 0; Y < GridSizeY; ++Y) {
                for (int Z = 0; Z < GridSizeZ; ++Z) {
                    float AverageX = 0, AverageY = 0, AverageZ = 0;
                    int Number = 0;

                    for(const auto& El : Grid[X][Y][Z]) {
                        Number++;
                        AverageX += El.X;
                        AverageY += El.Y;
                        AverageZ += El.Z;
                    }
                    if (Number > 0) {
                        AverageX /= Number;
                        AverageY /= Number;
                        AverageZ /= Number;
                        Cloud.emplace_back(Point(AverageX, AverageY, AverageZ));
                    }
                }
            }
        }
        return Cloud;
    }

    ~VoxelGrid() {}
};


#endif //VOXELGRID_HPP
