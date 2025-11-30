#pragma once
#include "figure.h"
#include "polygon_area.h"
#include <vector>

template <class T>
class Trapezoid : public Figure<T> {
private:
    std::vector<Point<T>> p;

public:
    Trapezoid(std::initializer_list<Point<T>> list) {
        if (list.size() != 4) throw std::logic_error("Trapezoid needs 4 points");
        p = list;
    }

    double area() const override {
        return polygon_area(p);
    }

    void print() const override {
        std::cout << "Трапеция: ";
        for (auto& t : p) std::cout << "(" << t.x << "," << t.y << ") ";
        std::cout << "\n";
    }

    operator double() const override {
        return area();
    }
};
