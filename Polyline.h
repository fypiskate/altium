#ifndef ALTIUM_POLYLINE_H
#define ALTIUM_POLYLINE_H

#include <climits>

struct Point {
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point() {
        this->x = INT_MAX;
        this->y = 0;
    }
};


struct Polyline {
    int size;
    std::vector<Point> points;
    Point left;
    bool reviewed;

    explicit Polyline(int size);

    void update_left(Point new_left);
    bool inside(Point p);
    bool operator<(Polyline const &pol) const;
};


#endif //ALTIUM_POLYLINE_H
