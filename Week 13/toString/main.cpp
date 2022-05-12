#include <bits/stdc++.h>

class Point
{
	public:
		int x, y;
};

class Convert
{
    public:
        static std::string toString(int n)
        {
        	// code here
        }
        static std::string toString(char c)
        {
        	// code here
        }
        static std::string toString(double d)
        {
        	// code here
        }
        static std::string toString(Point p)
        {
        	// code here
        }
};

int main()
{
	std::cout << Convert::toString(100) << std::endl;
	std::cout << Convert::toString('a') << std::endl;
	std::cout << Convert::toString(1.034) << std::endl;
	Point p;
	p.x = 1;
	p.y = 2;
	std::cout << Convert::toString(p) << std::endl;
}

/*
  output:
    100
    a
    1.034
    (1, 2)
*/
