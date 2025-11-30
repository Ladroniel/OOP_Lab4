#pragma once
#include <iostream>

template <class T>
class Figure {
public:
    virtual double area() const = 0;
    virtual void print() const = 0;
    virtual operator double() const = 0;
    virtual ~Figure() {}
};
