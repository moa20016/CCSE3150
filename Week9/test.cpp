#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Point3d.h"
#include "Triangle3d.h"
#define EPSILON 0.0001

TEST_CASE("Point3d") {
    SUBCASE("Default Constructor") {
        Point3d p;
        CHECK(p.get_x() == 0.0);
        CHECK(p.get_y() == 0.0);
        CHECK(p.get_z() == 0.0);
    }

    SUBCASE("Constructor with Parameters") {
        Point3d p(1.0, 2.0, 3.0);
        CHECK(p.get_x() == 1.0);
        CHECK(p.get_y() == 2.0);
        CHECK(p.get_z() == 3.0);
    }

    SUBCASE("Copy Constructor") {
        Point3d p1(1.0, 2.0, 3.0);
        Point3d p2(p1);
        CHECK(p2.get_x() == 1.0);
        CHECK(p2.get_y() == 2.0);
        CHECK(p2.get_z() == 3.0);
    }

    SUBCASE("Setters and Getters") {
        Point3d p;
        p.set_x(1.0);
        p.set_y(2.0);
        p.set_z(3.0);
        CHECK(p.get_x() == 1.0);
        CHECK(p.get_y() == 2.0);
        CHECK(p.get_z() == 3.0);
    }
}

TEST_CASE("Triangle3d") {
    Point3d p1(0.0, 0.0, 0.0);
    Point3d p2(1.0, 0.0, 0.0);
    Point3d p3(1.0, 1.0, 0.0);
    Triangle3d t(p1, p2, p3);

    SUBCASE("Check Points") {
        CHECK(t.get_p1().get_x() == 0.0);
        CHECK(t.get_p2().get_x() == 1.0);
        CHECK(t.get_p3().get_x() == 1.0);
    }

    SUBCASE("Point Distance") {
    Triangle3d t(p1, p2, p3);
    CHECK(t.pointDistance(p1, p2) == doctest::Approx(1.0));
}


    SUBCASE("Area Calculation") {
        t.area();
        CHECK(t.get_area() >= doctest::Approx(0.5 - EPSILON));
        CHECK(t.get_area() <= doctest::Approx(0.5 + EPSILON));
    }

    SUBCASE("Area Calculation 2") {
    Point3d p1(0.0, 0.0, 1.0);
    Point3d p2(1.0, 0.0, 0.0);
    Point3d p3(0.0, 1.0, 0.0); 
    Triangle3d t2(p1, p2, p3);
    t2.area();
    CHECK(t2.get_area() >= doctest::Approx(0.866 - EPSILON));
    CHECK(t2.get_area() <= doctest::Approx(0.866 + EPSILON));
}
}
