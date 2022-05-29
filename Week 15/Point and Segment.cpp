#include <bits/stdc++.h>

class Point
{
    float x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    void printPoint() { std::cout << "(" << x << ", " << y << ")"; }
    float getX() { return x; }
    float getY() { return y; }
    void setX(float _x) { x = _x; }
    void setY(float _y) { y = _y; }
    float getDistance(Point p) { return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)); }
};
class Segment
{
    Point point1, point2;

public:
    Segment()
    {
        point1.setX(0);
        point1.setY(0);
        point2.setX(0);
        point2.setY(0);
    }
    Segment(Point p1, Point p2)
    {
        point1.setX(p1.getX());
        point1.setY(p1.getY());
        point2.setX(p2.getX());
        point2.setY(p2.getY());
    }
    float getLength()
    {
        return point1.getDistance(point2);
    }
};
