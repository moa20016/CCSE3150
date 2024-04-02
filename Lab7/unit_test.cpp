#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "double_vector.h"

TEST_CASE("Square function") {
    CHECK_EQ(square(2.0), 4.0);
    CHECK_EQ(square(-3.0), 9.0);
    CHECK_EQ(square(0.0), 0.0);
}

TEST_CASE("Dot product function") {
    double_vector v1({1.0, 2.0}, 0);
    double_vector v2({-3.0, 4.0}, 1);
    CHECK_EQ(dot_product(v1, v2), 1.0*(-3.0) + 2.0*4.0);
}

TEST_CASE("Magnitude function") {
    double_vector v({3.0, 4.0}, 0);
    CHECK_EQ(magnitude(v), 5.0);
}

TEST_CASE("Cosine distance function") {
    // Test for 3D vectors
    double_vector v3({1.0, 1.0, 1.0}, 0);
    double_vector v4({1.0, 1.0, 0.0}, 1);
    CHECK_EQ(cosine_distance(v3, v4), doctest::Approx(0.61548).epsilon(0.00001));

    // Test for 5D vectors
    double_vector v5({1.0, 1.0, 1.0, 1.0, 1.0}, 2);
    double_vector v6({1.0, 1.0, 1.0, 1.0, 0.0}, 3);
    CHECK_EQ(cosine_distance(v5, v6), doctest::Approx(0.463648).epsilon(0.00001));
}




