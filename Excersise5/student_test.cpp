#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

TEST_CASE("calculateTotalScore") {
    student s;
    s.midterm = 80;
    s.final = 90;
    s.hw_grades = {85, 90, 95};

    double expected_score = 0.3 * s.midterm + 0.3 * s.final + 0.4 * ((85 + 90 + 95) / 3.0);
    double actual_score = calculateTotalScore(s);
    CHECK(actual_score == doctest::Approx(expected_score));
}

TEST_CASE("get_student") {
    // Test input/output by using std::stringstream
    std::stringstream input("123\nJohn Doe\n90\n80\n85\n95\n-1\n");
    std::cin.rdbuf(input.rdbuf());

    student s = get_student();

    CHECK(s.id == 123);
    CHECK(s.name == "John Doe");
    CHECK(s.final == 90);
    CHECK(s.midterm == 80);
    CHECK(s.hw_grades == std::vector<int>{85, 95});
}

TEST_CASE("print_student") {
    student s;
    s.id = 123;
    s.name = "John Doe";
    s.final = 90;
    s.midterm = 80;
    s.hw_grades = {85, 95};

    std::stringstream output;
    std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());
    print_student(s);
    std::cout.rdbuf(old_cout);

    std::string expected_output = "Student ID: 123\nStudent Name: John Doe\nFinal Exam Score: 90\nMidterm Exam Score: 80\nHomework Grades: 85 95 \nTotal Class Score: ";
    CHECK(output.str().find(expected_output) != std::string::npos);
}
