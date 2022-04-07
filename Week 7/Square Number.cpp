#include <iostream>
#include <cmath>

bool solve(int target)
{
	for (int i=1; i<=sqrt(target); i++)
		if (i*i == target)
			return true;
	return false;
}

int main()
{
    int a, b;
    while (std::cin >> a >> b && a != 0 && b != 0)
    {
    	int ans = 0;
    	while (a <= b)
	    	ans += solve(a++);
	    std::cout << ans << std::endl;
    }
}
