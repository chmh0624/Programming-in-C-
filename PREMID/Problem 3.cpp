#include <iostream>
int main()
{
    int fullCoke;
    while( std::cin >> fullCoke )
    {
        int sum = 0, empty = 0;
        while(fullCoke + empty > 2)
        {
            sum += fullCoke;
            empty += fullCoke;
            fullCoke = empty / 3;
            empty %= 3;
        }
        std::cout << sum + fullCoke + (fullCoke + empty == 2) << std::endl;
    }
    return 0;
}
