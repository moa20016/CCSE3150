#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "double_vector.h"

TEST_CASE("square") {
    CHECK(square(0.0) == 0.0);
    CHECK(square(1.0) == 1.0);
    CHECK(square(-1.0) == 1.0);
    CHECK(square(2.5) == 6.25);
    CHECK(square(-2.5) == 6.25);
}

TEST_CASE("dot_product") {
    double_vector v1;
    v1.x = 1.0;
    v1.y = 2.0;

    double_vector v2;
    v2.x = 3.0;
    v2.y = 4.0;

    CHECK(dot_product(v1, v2) == 11.0);
}

TEST_CASE("magnitude") {
    double_vector v;
    v.x = 3.0;
    v.y = 4.0;

    CHECK(magnitude(v) == 5.0);
}

TEST_CASE("cosine_distance") {
    double_vector v1;
    v1.x = 1.0;
    v1.y = 0.0;

    double_vector v2;
    v2.x = 0.0;
    v2.y = 1.0;

    CHECK(cosine_distance(v1, v2) == doctest::Approx(1.57079632679));
}
