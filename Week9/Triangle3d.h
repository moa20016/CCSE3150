#ifndef _TRIANGLE_3D_H_
#define _TRIANGLE_3D_H_

#include <iostream>

#include "Point3d.h"

using namespace std;

struct Triangle3d {

    Triangle3d();
    Triangle3d(const Triangle3d & p3d);
    Triangle3d(Point3d p1,Point3d p2, Point3d p3);
    ~Triangle3d();

private:
    Point3d p1;
    Point3d p2;
    Point3d p3;

    double s;
    double d12;
    double d13;
    double d23;
    double AreaIn3D;

public:
    Point3d & get_p1() { return p1; }
    Point3d & get_p2() { return p2; }
    Point3d & get_p3() { return p3; }

    double get_area() {return AreaIn3D;}
    double get_HeronsS() {return s;}

    double pointDistance(const Point3d left, const Point3d right);


    void heronsS();
    void area();


};

#endif
