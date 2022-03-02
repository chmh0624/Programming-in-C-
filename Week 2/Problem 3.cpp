#include <iostream>
#include <iomanip>

int main()
{
    double a;
    while (std::cin >> a)
  	    std::cout << std::fixed << std::setprecision(3) << a << std::endl;
}
