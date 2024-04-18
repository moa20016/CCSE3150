#include <iostream>
#include <cmath>

#include "Point3d.h"
#include "Triangle3d.h"

using namespace std;


std::ostream & operator<<(std::ostream &os, Triangle3d & triangle3d)
{
    
    os << "x = " << triangle3d.get_p1().get_x()
       << " y = " << triangle3d.get_p2().get_x()
       << " z = " << triangle3d.get_p3().get_x()
       <<"\n";
    if(0 != triangle3d.get_HeronsS()){
        os << "Area = " << triangle3d.get_area()
        <<"\n";
    }
    return os;
};

Triangle3d::Triangle3d() : p1{0.0}, p2{0.0}, p3{0.0}, d12{0.0}, d13{0.0}, d23{0.0}, s{0.0} {};
Triangle3d::Triangle3d(const Triangle3d & p3d) : p1(p3d.p1),p2(p3d.p2), p3(p3d.p3) {};
Triangle3d::Triangle3d(Point3d p1,Point3d p2, Point3d p3) :  p1{p1}, p2{p2}, p3{p3} {};
Triangle3d::~Triangle3d() {};

double square(double value) { return value * value; }

double Triangle3d::pointDistance(Point3d left, Point3d right) {
    double radicand = square(left.get_x() -right.get_x()) + square(left.get_y() -right.get_y()) + square(left.get_z() -right.get_z());

    return sqrt(radicand);
}
void Triangle3d::heronsS(){
    d12 = pointDistance(p1,p2);
    d13 = pointDistance(p1,p3);
    d23 = pointDistance(p2,p3);

    s = (d12 + d13 +d23)/2;
}
void Triangle3d::area(){
    heronsS();
    AreaIn3D = sqrt( s*(s-d12)*(s-d13)*(s-d23) );
}
