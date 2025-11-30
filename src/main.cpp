#include <memory>
#include <iostream>

#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include "array.h"

int main() {
    Array<std::shared_ptr< Figure<double> >> arr;

    arr.push_back(std::make_shared<Trapezoid<double>>(
        std::initializer_list<Point<double>>{
            {0,0}, {4,0}, {3,2}, {1,2}
        }
    ));

    arr.push_back(std::make_shared<Rhombus<double>>(
        std::initializer_list<Point<double>>{
            {0,0}, {2,1}, {0,2}, {-2,1}
        }
    ));

    arr.push_back(std::make_shared<Pentagon<double>>(
        std::initializer_list<Point<double>>{
            {0,0}, {2,0}, {3,2}, {1,3}, {-1,2}
        }
    ));

    arr.print();

    std::cout << "Общая площадь массива = "
              << arr.total_area()
              << "\n";
}
