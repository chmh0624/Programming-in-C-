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
      float p2a = sqrt((p.x - a.x) * (p.x - a.x) + (p.y - a.y) * (p.y - a.y));
      float p2b = sqrt((p.x - b.x) * (p.x - b.x) + (p.y - b.y) * (p.y - b.y));
      float segLen = getLength();
      if (p2a * p2a + segLen * segLen == p2b * p2b) return p2a;
      else if (p2b * p2b + segLen * segLen == p2a * p2a) return p2b;
      else
      {
        float segMid = segLen * p2a / (p2a + p2b);
        return sqrt(p2a * p2a - segMid * segMid);
      }
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
    static int isSamePoint(Point _a, Point _b)
    {
        return (_a.x == _b.x && _a.y == _b.y);
    }
    static bool isTriangle(Segment p, Segment q, Segment r) 
    {
      int count = isSamePoint(p.getPointA(), q.getPointA()) + isSamePoint(p.getPointA(), q.getPointB()) + isSamePoint(p.getPointA(), r.getPointA()) + isSamePoint(p.getPointA(), r.getPointB()) + isSamePoint(p.getPointB(), q.getPointA()) + isSamePoint(p.getPointB(), q.getPointB()) + isSamePoint(p.getPointB(), r.getPointA()) + isSamePoint(p.getPointB(), r.getPointB()) + isSamePoint(q.getPointA(), r.getPointA()) + isSamePoint(q.getPointA(), r.getPointB()) + isSamePoint(q.getPointB(), r.getPointA()) + isSamePoint(q.getPointB(), r.getPointB());
      return count == 3;
    }
    float getArea() const //return the area of triangle
    {
      float a = seg1.getLength(), b = seg2.getLength(), c = seg3.getLength(), s = (a + b + c)/2;
      return sqrt(s * (s-a) * (s-b) * (s-c));
    }   
private:
    Segment seg1, seg2, seg3;
};
