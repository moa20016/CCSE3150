#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <fstream>
#include <algorithm> 
#include <iterator>
#include <vector>
#include "exp_digraph.h"

TEST_CASE("ExpensiveDigraphExactPathsTest") {
    vector<vector<int>> DNeg1 = {{0, 0}, {0, 0}};
    vector<vector<int>> DZero = {{0, 0}, {0, 0}};
    vector<vector<int>> DPos1 = {{0, 0}, {0, 0}};
    expensiveDigraphExactPaths(DNeg1, DZero, DPos1);
    CHECK_EQ(DNeg1[0][0], 0);
    CHECK_EQ(DNeg1[0][1], 0);
}


TEST_CASE("read_ints function") {
    istringstream is("1 2 3 4 5");
    vector<int> result = read_ints(is);

    CHECK(result == vector<int>{1, 2, 3, 4, 5});
}

TEST_CASE("read_matrix function") {
    istringstream is("1 2 3\n4 5 6\n7 8 9");
    vector<vector<int>> result = read_matrix(is);

    CHECK(result == vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
}

// Additional test cases for read_matrix function
TEST_CASE("read_matrix function - empty input") {
    istringstream is("");
    vector<vector<int>> result = read_matrix(is);

    CHECK(result.empty());
}

TEST_CASE("read_matrix function - single element") {
    istringstream is("1");
    vector<vector<int>> result = read_matrix(is);

    CHECK(result == vector<vector<int>>{{1}});
}

TEST_CASE("read_matrix function - irregular matrix") {
    istringstream is("1 2\n3 4 5\n6 7");
    vector<vector<int>> result = read_matrix(is);

    CHECK(result == vector<vector<int>>{{1, 2}, {3, 4, 5}, {6, 7}});
}

// Additional test cases for operator<< functions
TEST_CASE("operator<< function - vector<int>") {
    stringstream ss;
    vector<int> my_vector = {1, 2, 3, 4, 5};
    ss << my_vector;

    CHECK(ss.str() == "1 2 3 4 5");
}

TEST_CASE("operator<< function - vector<vector<int>>") {
    stringstream ss;
    vector<vector<int>> my_matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ss << my_matrix;

    CHECK(ss.str() == "1 2 3\n4 5 6\n7 8 9");
}


