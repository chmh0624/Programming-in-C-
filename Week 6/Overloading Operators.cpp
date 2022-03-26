class Coordinate
{
public:
  Coordinate(){}
  Coordinate(const Coordinate &c) {x = c.x; y = c.y; }
  Coordinate(int _x, int _y) {x = _x; y = _y; }
  int getX() const { return x; }
  int getY() const { return y; }
  void setX(int val) { x = val; }
  void setY(int val) { y = val; }
  void showCoordInfo() const { std::cout << "(" << x << ", " << y << ")\n"; }
  int operator > (Coordinate &b){ return x > b.x & y > b.y; }
  int operator < (Coordinate &b){ return x < b.x & y < b.y; }
  Coordinate operator + (Coordinate &b)
  {
    Coordinate *c = new Coordinate(x + b.x, y + b.y);
    return *c;
  }
  Coordinate operator - (Coordinate &b)
  {
    Coordinate *c = new Coordinate(x - b.x, y - b.y);
    return *c;
  }
  Coordinate operator=(const Coordinate &c)
	{
		this -> x = c.x;
		this -> y = c.y;
		return *this;
	}
  
private:
  int x, y;
};
