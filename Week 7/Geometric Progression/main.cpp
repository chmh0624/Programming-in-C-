#include <iostream>
#include <cstdio>
#include <cmath>

// Finish the Class
class F{
private:
	// declare a, r
  // code here
  
public:
	// constructor
  F(double _a, double _r)
  {
    // code here
  }
  
  // Function at()
	double at(int x) 
  {
    // code here
  }
  
  // Function S()
	double *S()
	{
	  // code here
	}
};

int main()
{
	int j, k;
	double a, r;
	std::cin >> a >> r;
	F f(a, r);
	for(k = 0; k < 3; k ++)
		printf("%.2lf\n", f.at(k));
	double *s = f.S();
    if(s == NULL)
      printf("NULL\n");
    else
      printf("%.2lf\n", *s);
}
