#ifndef _DOUBLE_VECTOR_H_
#define _DOUBLE_VECTOR_H_

#include <iostream>
#include <vector>

struct double_vector {
    int id;
    std::vector<double> values;

    double_vector(const double_vector &dv) : id(dv.id), values(dv.values) {}
    double_vector() : id(0) {}
    double_vector(const std::vector<double> &vals, int id) : values(vals), id(id) {}
};

double square(const double &d);
double dot_product(const double_vector &one, const double_vector &two);
double magnitude(const double_vector &my_vector);
double cosine_distance(const double_vector &one, const double_vector &two);

#endif
