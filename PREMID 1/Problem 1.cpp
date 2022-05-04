#include <iostream>
class F
{
private:
  int a, b;
public:
  F(int _a, int _b){a = _a; b = _b;}
  int f(int x) { return a*x+b; }
  int S(int x)
  {
    int sum = 0;
  	for (int i=0; i<=x; i++) sum += f(i);
    return sum;
  }
  int G(int x, int y)
  {
    int sum = 0;
  	for (int i=x; i<=y; i++) sum += f(i);
    return sum;
  }
};
int main() {
  int a, b, j;
  std::cin>>a>>b;
  F f(a, b);
  for(j = 0;j < 10;j ++)
  {
    int x, y;
    std::cin>>x>>y;
    std::cout<<f.S(x)<<std::endl;
    std::cout<<f.G(x, y)<<std::endl;
  }
  return 0;
}
