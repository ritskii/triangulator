#ifndef OCTREE_HPP
#define OCTREE_HPP

class Octree {
public:
    Point Min, Max;
    std::vector<Point> Elements;
    std::array<Octree*, 8> Childs;

    Octree(Point Min, Point Max) : Min(Min), Max(Max) {
        Childs.fill(nullptr);
    }

    Octree(Point Min, Point Max, std::vector<Point>& Cloud) : Min(Min), Max(Max) {
        Childs.fill(nullptr);

        for (const auto& El : Cloud) {
            insert(El);
        }
    }

    bool contains(const Point& Element) const {
        return Element.X >= Min.X && Element.X <= Max.X &&
            Element.Y >= Min.Y && Element.Y <= Max.Y &&
                Element.Z >= Min.Z && Element.Z <= Max.Z;
    }

    bool isLeaf() const {
        return Childs[0] == nullptr;
    }

    void subdivide() {
        Point Mid = {(Min.X + Max.X) / 2, (Min.Y + Max.Y) / 2, (Min.Z + Max.Z) / 2};

        Childs[0] = new Octree(Min, Mid);
        Childs[1] = new Octree({Mid.X, Min.Y, Min.Z}, {Max.X, Mid.Y, Mid.Z});
        Childs[2] = new Octree({Min.X, Min.Y, Mid.Z}, {Mid.X, Mid.Y, Max.Z});
        Childs[3] = new Octree({Mid.X, Min.Y, Mid.Z}, {Max.X, Mid.Y, Max.Z});
        Childs[4] = new Octree({Min.X, Mid.Y, Min.Z}, {Mid.X, Max.Y, Mid.Z});
        Childs[5] = new Octree({Mid.X, Mid.Y, Min.Z}, {Max.X, Max.Y, Mid.Z});
        Childs[6] = new Octree({Min.X, Mid.Y, Mid.Z}, {Mid.X, Max.Y, Max.Z});
        Childs[7] = new Octree(Mid, Max);
    }

    void insert(const Point& P) {
        if (!contains(P)) return;

        if (isLeaf() && Elements.size() < 8) {
            Elements.push_back(P);
            return;
        }

        if (isLeaf()) {
            subdivide();
            for (const auto& Point : Elements) {
                for (int I = 0; I < 8; ++I) {
                    Childs[I]->insert(Point);
                }
            }
            Elements.clear();
        }

        for (int I = 0; I < 8; ++I) {
            Childs[I]->insert(P);
        }
    }

    ~Octree() {
        for (auto* Child : Childs) {
            delete Child;
        }
    }
};

#endif //OCTREE_HPP
