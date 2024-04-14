#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Point3d.h"
#include "Triangle3d.h"

TEST_CASE("Point 3D") {
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
}

TEST_CASE("Triangle 3D") {
    Point3d p1(1.0, 1.0, 1.0);
    Point3d p2(2.0, 2.0, 2.0);
    Point3d p3(3.0, 3.0, 3.0);

    Triangle3d t(p1, p2, p3);

    SUBCASE("Check Points") {
        CHECK(t.get_p1().get_x() == 1.0);
        CHECK(t.get_p2().get_x() == 2.0);
        CHECK(t.get_p3().get_x() == 3.0);
    }

    SUBCASE("Point Distance") {
        CHECK(t.pointDistance(p1, p2) == sqrt(3.0));
    }
}
