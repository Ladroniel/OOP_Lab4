#pragma once
#include <vector>
#include <cmath>
#include "point.h"

template <class T>
double polygon_area(const std::vector<Point<T>>& p) {
    double s = 0.0;
    size_t n = p.size();
    for (size_t i = 0; i < n; i++) {
        s += p[i].x * p[(i + 1) % n].y - p[(i + 1) % n].x * p[i].y;
    }
    return std::abs(s) * 0.5;
}
