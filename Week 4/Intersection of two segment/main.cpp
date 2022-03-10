#include <iostream>
#include <cmath>

class Coordinate
{
public:
  Coordinate()
  {
    x = 0;
    y = 0;
  }
  Coordinate(int _x, int _y)
  {
    x = _x;
    y = _y;
  }
  Coordinate(const Coordinate &obj)
  {
    x = obj.x;
    y = obj.y;
  }
  int getX()
  {
    return x;
  }
  int getY()
  {
    return y;
  }
  void setX(int _x)
  {
    x = _x;
  }
  void setY(int _y)
  {
    y = _y;
  }
  void showCoordInfo()
  {
    std::cout << "(" << x << ", " << y << ")\n";
  }

private:
  int x, y;
};

class Segment // using two Coordinate to represent a segment
{

public:
  Segment(Coordinate _a, Coordinate _b)
  {
    // constructor
  }
  
  Coordinate *getIntersection(Segment S)
  {
    // code here
  }

  float length() 
  {
    // return the length of segment
  }

  Coordinate getCoordinateA() { return a; }

  Coordinate getCoordinateB() { return b; }

private:
  Coordinate a, b;
};


int main()
{
  // set the coordinate x, y
  Coordinate a = Coordinate();
  Coordinate b = Coordinate();
  Coordinate c = Coordinate();
  Coordinate d = Coordinate();
  Segment s1 = Segment(a, b);
  Segment s2 = Segment(c, d);
  if (s1.getIntersection(s2) == NULL)
		std::cout << "NULL" << std::endl;
  else
		s1.getIntersection(s2) -> showCoordInfo();
}
