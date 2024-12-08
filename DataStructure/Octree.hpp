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
        Point mid = {(Min.X + Max.X) / 2, (Min.Y + Max.Y) / 2, (Min.Z + Max.Z) / 2};

        Childs[0] = new Octree(Min, mid);
        Childs[1] = new Octree({mid.X, Min.Y, Min.Z}, {Max.X, mid.Y, mid.Z});
        Childs[2] = new Octree({Min.X, Min.Y, mid.Z}, {mid.X, mid.Y, Max.Z});
        Childs[3] = new Octree({mid.X, Min.Y, mid.Z}, {Max.X, mid.Y, Max.Z});
        Childs[4] = new Octree({Min.X, mid.Y, Min.Z}, {mid.X, Max.Y, mid.Z});
        Childs[5] = new Octree({mid.X, mid.Y, Min.Z}, {Max.X, Max.Y, mid.Z});
        Childs[6] = new Octree({Min.X, mid.Y, mid.Z}, {mid.X, Max.Y, Max.Z});
        Childs[7] = new Octree(mid, Max);
    }

    void insert(const Point& p) {
        if (!contains(p)) return;

        if (isLeaf() && Elements.size() < 8) {
            Elements.push_back(p);
            return;
        }

        if (isLeaf()) {
            subdivide();
            for (const auto& point : Elements) {
                for (int i = 0; i < 8; ++i) {
                    Childs[i]->insert(point);
                }
            }
            Elements.clear();
        }

        for (int i = 0; i < 8; ++i) {
            Childs[i]->insert(p);
        }
    }

    ~Octree() {
        for (auto* child : Childs) {
            delete child;
        }
    }
};

#endif //OCTREE_HPP
