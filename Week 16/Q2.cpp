template<typename T>
class point
{
private:
  T x, y;
public:
  point(){}
  point(T a, T b) { x = a; y = b; }
  friend std::ostream& operator<<(std::ostream& os, const point& p) 
  { 
    os << p.x << " " << p.y << std::endl; 
    return os; 
  }
  point operator +(point &p) 
  {
    return point(x+=p.x, y+=p.y); 
  }
};
