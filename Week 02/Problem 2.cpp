#include <iostream>

void f()
{
	  char c;
	  std::cin >> c;
	  if (c != '.')
		  f();
		  std::cout << c;
}

int main()
{
	  f();	
}
