#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "perfect_number.h"

TEST_CASE("isPerfect function") {
    CHECK(isPerfect(6) == true);
    CHECK(isPerfect(28) == true);
    CHECK(isPerfect(12) == false);
    CHECK(isPerfect(9) == false);
    CHECK(isPerfect(496) == true);
    CHECK(isPerfect(8128) == true);
    CHECK(isPerfect(33550336) == true);
    CHECK(isPerfect(33550337) == false);
    CHECK(isPerfect(1) == false); 
    CHECK(isPerfect(2) == false); 
    CHECK(isPerfect(3) == false); 
    CHECK(isPerfect(4) == false); 
    CHECK(isPerfect(5) == false); 
}
