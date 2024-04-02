#include <cmath>
#include "double_vector.h"

double square(const double &d) {
    return d * d;
}

double dot_product(const double_vector &one, const double_vector &two) {
    double result = 0.0;
    for (size_t i = 0; i < one.values.size(); ++i) {
        result += one.values[i] * two.values[i];
    }
    return result;
}

double magnitude(const double_vector &my_vector) {
    double result = 0.0;
    for (double value : my_vector.values) {
        result += square(value);
    }
    return sqrt(result);
}

double cosine_distance(const double_vector &one, const double_vector &two) {
    double dot_prod = dot_product(one, two);
    double one_magnitude = magnitude(one);
    double two_magnitude = magnitude(two);

    double d = dot_prod / (one_magnitude * two_magnitude);
    if (d > 1.0)
        d = 1.0;
    if (d < -1.0)
        d = -1.0;

    return acos(d);
}
