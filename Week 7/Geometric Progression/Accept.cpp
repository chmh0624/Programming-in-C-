#include <iostream>
#include <cstdio>
#include <cmath>

// Finish the Class
class F{
private:
	double a, r;
public:
	F(double _a, double _r) { a = _a; r = _r; }
	double at(int x) { return a * pow(r, x); }
	double *S()
	{
		if (r >= 1 || r <= -1)
			return nullptr;
		double *n = new double;
		*n = a / (1 - r);
		return n;
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
