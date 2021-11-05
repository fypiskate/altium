#include <iostream>
#include <vector>
#include <algorithm>

#include "Polyline.h"

void find_polylines(std::vector<Polyline> &polylines, int id_cur, bool open_status,
                    std::vector<std::vector<Polyline>> &components, int parent_component) {
    Polyline &cur_polyline = polylines[id_cur];
    cur_polyline.reviewed = true;

    if (open_status) {
        std::vector<Polyline> new_component;
        new_component.push_back(cur_polyline);
        components.push_back(new_component);
        parent_component = components.size() - 1;
    } else {
        components[parent_component].push_back(cur_polyline);
    }

    for (int i = 0; i < polylines.size(); ++i) {
        if (!polylines[i].reviewed && cur_polyline.inside(polylines[i].left)) {
            find_polylines(polylines, i, !open_status, components, parent_component);
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin >> n;
    std::vector<Polyline> polylines;
    std::vector<std::vector<Polyline>> components;
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        Polyline cur_polyline(m);
        for (int j = 0; j < m; ++j) {
            int x, y;
            std::cin >> x >> y;
            Point cur_point(x, y);
            cur_polyline.points.push_back(cur_point);
            cur_polyline.update_left(cur_point);
        }
        polylines.push_back(cur_polyline);
    }
    std::sort(polylines.begin(), polylines.end());

    bool open_status = true;

    for (int i = 0; i < n; ++i) {
        if (!polylines[i].reviewed) {
            find_polylines(polylines, i, open_status, components, components.size());
        }
    }

    for (int i = 0; i < components.size(); ++i) {
        std::cout << "Component " << i + 1 << ":\n";
        for (auto &c: components[i]) {
            for (int k = 0; k < c.size; ++k) {
                std::cout << "(" << c.points[k].x << ";" << c.points[k].y << ") ";
            }
            std::cout << "\n";
        }
    }
    return 0;
}