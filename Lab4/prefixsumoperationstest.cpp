#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefixsumoperations.h"

TEST_CASE("fillWithOnesAndNegOnes") {
    std::vector<int> result = fillWithOnesAndNegOnes(3);
    std::vector<int> expected{1, 1, 1, -1, -1, -1}; 
    CHECK(result.size() == expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        CHECK(result[i] == expected[i]);
    }
}


TEST_CASE("calculatePrefixSum") {
    std::vector<int> input{1, 2, 3, -1, -2, -3};
    std::vector<int> result = calculatePrefixSum(input);
    CHECK(result == std::vector<int>{1, 3, 6, 5, 3, 0});
}

TEST_CASE("findLowestPrefixSumIndex") {
    std::vector<int> input{1, 3, 6, 5, 3, 0};
    int result = findLowestPrefixSumIndex(input);
    CHECK(result == 5);
}

TEST_CASE("splitAtIndex") {
    std::vector<int> input{1, 1, 1, -1, -1, -1};
    std::vector<int> p1, p2;
std::tie(p1, p2) = splitAtIndex(input, 2);

    CHECK(p1 == std::vector<int>{1, 1, 1});
    CHECK(p2 == std::vector<int>{-1, -1, -1});
}

TEST_CASE("p1p2") {
    std::vector<int> p1{1, 1, 1};
    std::vector<int> p2{-1, -1, -1};
    p1p2(p1, p2);
    CHECK(p1.back() == 1);
    CHECK(p2.front() == 1);
}


TEST_CASE("concatenateArrays") {
    std::vector<int> p1{1, 1, 1};
    std::vector<int> p2{-1, -1, -1};
    std::vector<int> result = concatenateArrays(p1, p2);
    std::vector<int> expected{1, 1, 1, -1, -1, -1};
    CHECK(result == expected);
}

TEST_CASE("createNonCrossingPrefixSum") {
    std::vector<int> result = createNonCrossingPrefixSum(2);
    CHECK(result == std::vector<int>{1, 1, -1, -1});
}

