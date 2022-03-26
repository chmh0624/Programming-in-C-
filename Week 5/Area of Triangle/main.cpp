#include <iostream>
#include <math.h>

class Point
{
public:
    Point () {}
    Point (int _x, int _y) {x = _x; y = _y;}
    float x, y;
};

class Segment
{
public:
    Segment()
    {
    }
    Segment(Point _a, Point _b)
    {
        a = _a;
        b = _b;
    }
    Point getPointA() const
    {
        return a;
    }
    Point getPointB() const
    {
        return b;
    }
    void setPoint(Point _a, Point _b)
    {
        a.x = _a.x;
        a.y = _a.y;
        b.x = _b.x;
        b.y = _b.y;
    }
    float getLength() const
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
    float getDistance(const Point &p) 
    {
      // code here
    }
private:
    Point a, b;
};

class Triangle
{
public:
    Triangle(Segment s1, Segment s2, Segment s3)
    {
        seg1 = s1;
        seg2 = s2;
        seg3 = s3;
    }
    static bool isTriangle(Segment p, Segment q, Segment r) 
    {
      // code here
    }
    float getArea() const //return the area of triangle
    {
      // code here
    }   
private:
    Segment seg1, seg2, seg3;
};

int main()
{
    Point a(0,0), b(1,0), c(1,1), d(1,0), e(0,0), f(1,1);
    Segment s1(a, b), s2(c, d), s3(e, f);
    Triangle t(s1, s2, s3);
    std::cout << t.isTriangle(s1, s2, s3);
    return 0;
}
