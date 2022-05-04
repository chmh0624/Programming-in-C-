#include <iostream>
#define PI 3.14

class Shape
{
    public:
        virtual double getArea() = 0;
};
class Circle: public Shape
{
    public:
        double r;
        Circle(double _r) {r = _r;}
        double getArea(){ return PI*r*r;}
};
class Rectangle: public Shape
{
    public:
        double w, h;
        Rectangle(double _w, double _h) {w = _w; h = _h;}
        double getArea() {return w*h;}
};

int main() {
    int a, b, c;
    std::cin >> a >> b >>c;
    Circle c1(a);
    Rectangle r(b, c);
    std::cout<<c1.getArea()<<std::endl;
    std::cout<<r.getArea()<<std::endl;
    return 0;
}
