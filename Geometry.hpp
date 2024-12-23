#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

enum TriType {
    Dela
};

struct Point {
    float x, y;

    Point(float X, float Y) : x(X), y(Y) {}

    void print() const {
        std::cout << "[" << x << ", " << y << "]\n";
    }
};

struct Bezier {
    std::vector<Point> points;

    Bezier(std::vector<Point>& Input) {
        for(float i = 0; i < 1.01;  i += 0.1) {
            Point First(
                lerp(Input[0].x, Input[1].x, i),
                lerp(Input[0].y, Input[1].y, i)
                );

            Point Second(
                lerp(Input[1].x, Input[2].x, i),
                lerp(Input[1].y, Input[2].y, i)
                );

            Point Result(
                lerp(First.x, Second.x, i),
                lerp(First.y, Second.y, i)
                );

            points.emplace_back(Result);
        }
    }

    void print() {
        for(const auto& el : points) {
            el.print();
        }
    }
};

#endif //GEOMETRY_HPP
