#pragma once
#include <iostream>

template <class T>
class Point {
public:
    T x, y;

    Point() : x(0), y(0) {}
    Point(T x_, T y_) : x(x_), y(y_) {}
};
