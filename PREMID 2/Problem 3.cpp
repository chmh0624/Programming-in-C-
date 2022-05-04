// Watch Out Overflow!! long instead int! 

#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    while (n--)
    {
        long s, d;
        std::cin >> s >> d;
        if (s - d < 0 || (s+d)%2 || (s-d)%2)
            std::cout << "impossible\n";
        else
            std::cout << (s+d)/2 << " " << (s-d)/2 << std::endl;
    }
}
