#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct student {
  int id;
  string name;
  int final;
  int midterm;
  vector<int> hw_grades;
};
double calculateTotalScore(const student& s);
student get_student();
void print_student(student s);

#endif
