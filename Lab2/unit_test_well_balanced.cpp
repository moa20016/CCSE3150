#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "well_balanced.h"

#include <vector>
#include <algorithm>

TEST_CASE("Well-Balanced List Generation") {
    std::srand(std::time(0));
    int iterations = 5000;

    for (int i = 0; i < iterations; ++i) {
        SUBCASE("Generated list is well-balanced") {
            std::vector<int> sequence = generateWellBalancedList(3);
            CHECK(isWellBalanced(sequence));
        }
    }
}
