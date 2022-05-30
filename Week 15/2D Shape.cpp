#include <bits/stdc++.h>
using namespace std;
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
    bool operator==(Point &p) { return (x == p.x && y == p.y); }
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
    bool check(Segment &s)
    {
        return (point1 == s.point1 || point1 == s.point2 || point2 == s.point1 || point2 == s.point2);
    }
    float getLength()
    {
        return point1.getDistance(point2);
    }
};

class Shape
{
public:
    Shape() { edgeCount = 0; }
    Shape(Segment *s, int cnt)
    {

        int n = 0;
        for (int i = 0; i < cnt; i++)
            for (int j = 0; j < cnt; j++)
                if (i != j)
                    n += (s[i].check(s[j]));
        if (n != 2 * cnt)
            throw std::invalid_argument("");
        edgeCount = cnt;
        for (int i = 0; i < cnt; i++)
            seg[i] = s[i];
    }
    virtual float getArea() = 0;
    float getPerimeter()
    {
        float per = 0;
        for (auto i : seg)
            per += i.getLength();
        return per;
    }
    Segment &getSeg(int index)
    {
        return seg[index];
    }

private:
    Segment seg[10];
    int edgeCount;
};
