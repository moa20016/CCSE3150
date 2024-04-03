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
    double_vector v5({1.0, 3.6, 1.9}, 2);
    double_vector v6({1.0, 4.5, 3.2}, 3);
    CHECK_EQ(cosine_distance(v5, v6), doctest::Approx(0.14353).epsilon(0.00001));
    double_vector v7({2.7,7,6}, 4);
    double_vector v8({9,11.5,22.99}, 5);
    CHECK_EQ(cosine_distance(v7, v8), doctest::Approx(0.38250).epsilon(0.00001));

    // Test for 5D vectors
    double_vector v9({1.0, 1.0, 1.0, 1.0, 1.0}, 6);
    double_vector v10({1.0, 1.0, 1.0, 1.0, 0.0}, 7);
    CHECK_EQ(cosine_distance(v9, v10), doctest::Approx(0.463648).epsilon(0.00001));
    double_vector v11({1,3.6,1.9,0.98,-4}, 8);
    double_vector v12({1,2.5,0.5,0.99,1.5}, 9);
    CHECK_EQ(cosine_distance(v11, v12), doctest::Approx(1.258165).epsilon(0.00001));
    double_vector v13({1,4.5,3.2,0.71,8.2}, 10);
    double_vector v14({2.7,7,6,9.5,-5.44}, 11);
    CHECK_EQ(cosine_distance(v13, v14), doctest::Approx( 1.4635).epsilon(0.00001));
}




