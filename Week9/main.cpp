#include <iostream>
#include <cmath>
#include "Triangle3d.h"

using namespace std;

int main() {
    Point3d p1(0.0, 0.0, 0.0);
    Point3d p2(1.0, 2.0, 0.0);
    Point3d p3(-1.0, 0.0, 0.0);

    Triangle3d triangle(p1, p2, p3);
    cout << "Distance between p1 and p2: " << triangle.pointDistance(p1, p2) << endl;
    cout << "Expected distance: sqrt(5) = " << sqrt(5.0) << endl;

    triangle.area();
    cout << "Area of the triangle: " << triangle.get_area() << endl;

    return 0;
}
