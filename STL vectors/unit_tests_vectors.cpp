#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"


#include <vector>
#include "myfind.h"
#include "int_vector.h"



TEST_CASE("myfind") {
  
  SUBCASE("Edge cases") {
    std::vector<int> x_0 = {};  
    bool answer = myfind<int,greaterThan>(x_0,99);
    CHECK(false == answer);

    std::vector<int> x_1 = {-17};  
    answer = myfind<int,greaterThan>(x_1, -17);
    CHECK(true == answer);
    
    answer = myfind<int,greaterThan>(x_1, 555);
    CHECK(false == answer);

  };

  
  SUBCASE("Small cases") {
    std::vector<int> x = {1,5,8,11,25,30,32,47,78,99,101};
    bool foundIt_not = myfind<int,greaterThan>(x,33);
    CHECK(false == foundIt_not);

    bool foundIt_did = myfind<int,greaterThan>(x,x[4]);
    CHECK(true == foundIt_did);

  };
}

TEST_CASE("Test int_vector output operator") {
    int_vector i_vec_1(9, 1, 2);
    std::stringstream ss;
    ss << i_vec_1.id << " " << i_vec_1.from << " " << i_vec_1.to;

    std::string expected_output = "9 1 2";
    std::string actual_output = ss.str();
    CHECK(expected_output == actual_output);
}


TEST_CASE("Test int_vector copy constructor") {
    int_vector i_vec_1(9, 1, 2);
    int_vector i_vec_2(i_vec_1);

    CHECK(i_vec_1.id == i_vec_2.id);
    CHECK(i_vec_1.from == i_vec_2.from);
    CHECK(i_vec_1.to == i_vec_2.to);
}



