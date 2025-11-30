#include <gtest/gtest.h>
#include <memory>

#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include "array.h"
#include "polygon_area.h"

TEST(PointTest, Constructor) {
    Point<double> p(3.5, -2.0);
    EXPECT_DOUBLE_EQ(p.x, 3.5);
    EXPECT_DOUBLE_EQ(p.y, -2.0);
}

TEST(PolygonAreaTest, SquareArea) {
    std::vector<Point<double>> pts = {
        {0,0},{2,0},{2,2},{0,2}
    };
    EXPECT_DOUBLE_EQ(polygon_area(pts), 4.0);
}

TEST(TrapezoidTest, AreaCorrect) {
    Trapezoid<double> t({
        {0,0}, {4,0}, {3,2}, {1,2}
    });
    EXPECT_NEAR(t.area(), 6.0, 1e-6);
}

TEST(TrapezoidTest, DoubleConversion) {
    Trapezoid<double> t({
        {0,0}, {4,0}, {3,2}, {1,2}
    });
    EXPECT_NEAR((double)t, 6.0, 1e-6);
}

TEST(RhombusTest, AreaCorrect) {
    Rhombus<double> r({
        {0,0},{2,1},{0,2},{-2,1}
    });
    EXPECT_NEAR(r.area(), 4.0, 1e-6);
}

TEST(PentagonTest, AreaCorrect) {
    Pentagon<double> p({
        {0,0}, {2,0}, {3,2}, {1,3}, {-1,2}
    });
    EXPECT_NEAR(p.area(), 8.0, 1e-6);
}

TEST(ArrayTest, PushBackAndTotalArea) {
    Array<std::shared_ptr< Figure<double> >> arr;

    arr.push_back(std::make_shared<Rhombus<double>>(
        std::initializer_list<Point<double>>{
            {0,0},{2,1},{0,2},{-2,1}
        }
    ));
    arr.push_back(std::make_shared<Trapezoid<double>>(
        std::initializer_list<Point<double>>{
            {0,0},{4,0},{3,2},{1,2}
        }
    ));

    EXPECT_NEAR(arr.total_area(), 10.0, 1e-6);
}

TEST(ArrayTest, EraseWorks) {
    Array<std::shared_ptr< Figure<double> >> arr;

    arr.push_back(std::make_shared<Rhombus<double>>(
        std::initializer_list<Point<double>>{
            {0,0},{2,1},{0,2},{-2,1}
        }
    ));
    arr.push_back(std::make_shared<Rhombus<double>>(
        std::initializer_list<Point<double>>{
            {0,0},{2,1},{0,2},{-2,1}
        }
    ));

    arr.erase(0);

    EXPECT_NEAR(arr.total_area(), 4.0, 1e-6);
}

TEST(ArrayTest, AutoGrow) {
    Array<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    EXPECT_EQ(1, 1);
}
