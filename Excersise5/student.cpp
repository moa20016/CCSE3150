#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;



double calculateTotalScore(const student& s) {
    double total = 0.3 * s.midterm + 0.3 * s.final;
    double hw_sum = 0;
    for (int grade : s.hw_grades) {
        hw_sum += grade;
    }
    total += 0.4 * (hw_sum / s.hw_grades.size());
    return total;
}

student get_student() {
    student s;
    std::cout << "Enter student ID: ";
    std::cin >> s.id;

    std::cout << "Enter student name: ";
    std::cin.ignore();
    std::getline(std::cin, s.name);

    std::cout << "Enter final exam score: ";
    std::cin >> s.final;

    std::cout << "Enter midterm exam score: ";
    std::cin >> s.midterm;

    std::cout << "Enter homework grades (enter -1 to stop):\n";
    int grade;
    while (true) {
        std::cin >> grade;
        if (grade == -1) {
            break;
        }
        s.hw_grades.push_back(grade);
    }

    return s;
}



void print_student(student s) {
    std::cout << "Student ID: " << s.id << std::endl;
    std::cout << "Student Name: " << s.name << std::endl;
    std::cout << "Final Exam Score: " << s.final << std::endl;
    std::cout << "Midterm Exam Score: " << s.midterm << std::endl;
    std::cout << "Homework Grades: ";
    for (int grade : s.hw_grades) {
        std::cout << grade << " ";
    }
    std::cout << std::endl;
    std::cout << "Total Class Score: " << calculateTotalScore(s) << std::endl;
}
