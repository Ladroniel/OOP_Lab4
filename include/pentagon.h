#pragma once
#include "figure.h"
#include "polygon_area.h"
#include <vector>

template <class T>
class Pentagon : public Figure<T> {
private:
    std::vector<Point<T>> p;

public:
    Pentagon(std::initializer_list<Point<T>> list) {
        if (list.size() != 5) throw std::logic_error("Pentagon needs 5 points");
        p = list;
    }

    double area() const override {
        return polygon_area(p);
    }

    void print() const override {
        std::cout << "Пятиугольник: ";
        for (auto& t : p) std::cout << "(" << t.x << "," << t.y << ") ";
        std::cout << "\n";
    }

    operator double() const override {
        return area();
    }
};
