#include <iostream>

int main()
{
    int Case, cnt = 1;
    while (std::cin >> Case && Case)
    {
        int *standard = new int[Case];
        for (int i = 0; i < Case; i++)
            std::cin >> standard[i];
        std::cout << "Game " << cnt++ << ":" << std::endl;
        while (1)
        {
            int *test = new int[Case];
            int *flag1 = new int[Case];
            int *flag2 = new int[Case];
            int same = 0, dif = 0;
            for (int i = 0; i < Case; i++)
            {
                std::cin >> test[i];
                flag1[i] = !(test[i] == standard[i]);
                flag2[i] = !(test[i] == standard[i]);
                same += (test[i] == standard[i]);
            }
            if (test[0] == 0)
                break;
            for (int i = 0; i < Case; i++)
            {
                if (flag1[i])
                {
                    for (int j = 0; j < Case; j++)
                    {
                        if (flag2[j] && standard[j] == test[i])
                        {
                            flag2[j] = 0;
                            flag1[i] = 0;
                            dif++;
                            break;
                        }
                    }
                }
            }
            delete[] test;
            delete[] flag1;
            delete[] flag2;
            std::cout << "(" << same << "," << dif << ")\n";
        }
        delete[] standard;
    }
}
