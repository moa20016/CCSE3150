#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "prefix_sum.h"

int test_ary_0[] = {0};
int test_ary_1[] = {1, -2};
int test_ary_2[] = {-1, -2, -5};
int test_ary_3[] = {1, -1, 1, -1};
int test_ary_4[] = {1, 1, -1, -1};
int test_ary_5[] = {1, 2, 3, 4, -10};

TEST_CASE("prefix sum") {
    CHECK_EQ(prefix_sum(test_ary_0, 0), 0);
    CHECK_EQ(prefix_sum(test_ary_1, sizeof(test_ary_1) / sizeof(test_ary_1[0])), -1);
    CHECK_EQ(prefix_sum(test_ary_2, sizeof(test_ary_2) / sizeof(test_ary_2[0])), -8);
    CHECK_EQ(prefix_sum(test_ary_3, sizeof(test_ary_3) / sizeof(test_ary_3[0])), 0);
    CHECK_EQ(prefix_sum(test_ary_4, sizeof(test_ary_4) / sizeof(test_ary_4[0])), 0);
    CHECK_EQ(prefix_sum(test_ary_5, sizeof(test_ary_5) / sizeof(test_ary_5[0])), 0);

    SUBCASE("non-negative") {
        CHECK(non_neg_prefix_sum(test_ary_0, 0) == true);
        CHECK(non_neg_prefix_sum(test_ary_1, sizeof(test_ary_1) / sizeof(test_ary_1[0])) == false);
        CHECK(non_neg_prefix_sum(test_ary_2, sizeof(test_ary_2) / sizeof(test_ary_2[0])) == false);
        CHECK(non_neg_prefix_sum(test_ary_3, sizeof(test_ary_3) / sizeof(test_ary_3[0])) == true);
        CHECK(non_neg_prefix_sum(test_ary_4, sizeof(test_ary_4) / sizeof(test_ary_4[0])) == true);
        CHECK(non_neg_prefix_sum(test_ary_5, sizeof(test_ary_5) / sizeof(test_ary_5[0])) == true);
    }

    SUBCASE("non-positive") {
        CHECK(non_pos_prefix_sum(test_ary_0, 0) == true);
        CHECK_FALSE(non_pos_prefix_sum(test_ary_1, sizeof(test_ary_1) / sizeof(test_ary_1[0])) == true);
        CHECK(non_pos_prefix_sum(test_ary_2, sizeof(test_ary_2) / sizeof(test_ary_2[0])) == true);
        CHECK(non_pos_prefix_sum(test_ary_3, sizeof(test_ary_3) / sizeof(test_ary_3[0])) == false);
        CHECK(non_pos_prefix_sum(test_ary_4, sizeof(test_ary_4) / sizeof(test_ary_4[0])) == false);
        CHECK(non_pos_prefix_sum(test_ary_5, sizeof(test_ary_5) / sizeof(test_ary_5[0])) == false);
    }
}