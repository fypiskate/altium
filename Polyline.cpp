#include <vector>
#include "Polyline.h"

Polyline::Polyline(int siz) {
    size = siz;
    points = std::vector<Point>();
    left = Point();
    reviewed = false;
}

void Polyline::update_left(Point new_left) {
    if (new_left.x < left.x) {
        left = new_left;
    }
}

bool Polyline::inside(Point p) {
    int intersections = 0;
    for (int i = 0; i < size; ++i) {
        Point min_point = points[i];
        Point max_point = points[(i + 1) % size];
        if (min_point.y > max_point.y) {
            std::swap(min_point, max_point);
        }
        if (max_point.y < p.y || min_point.y >= p.y) {
            continue;
        }
        int orient = (p.x - min_point.x) * (max_point.y - min_point.y) -
                     (p.y - min_point.y) * (max_point.x - min_point.x);
        if (orient < 0) {
            intersections++;
        }
    }
    return intersections % 2;
}

bool Polyline::operator<(const Polyline &pol) const {
    return left.x < pol.left.x;
}
