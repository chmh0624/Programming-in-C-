#include <iostream>
#include <vector>

std::vector <std::string> bin;

int main()
{
    std::string input;
    while (std::cin >> input && input != "#")
    {
        if (input[0] == 'e')
        {
            int *cntArr = new int[bin.size()];
            for (int i=0; i<bin.size(); i++)
            {
                cntArr[i] = 0;
                for (int j=0; j<5; j++)
                {
                    for (int k=0; k<bin.size(); k++)
                    {
                        if (bin[i][j] != bin[k][j])
                            cntArr[i] += 1;
                    }
                }
            }
            int min = 1000000, minid = 0;
            for (int i=0; i<bin.size(); i++)
                {
                    if (min > cntArr[i])
                    {
                        min = cntArr[i];
                        minid = i;
                    }
                }
            delete [] cntArr;
            bin.clear();
            std::cout << minid + 1 << std::endl;
        }
        else
        {
            std::string s;
            char r, o, y, g, b;
            for (int i=0; i<input.length(); i+=4)
            {
                if (input[i] == 'r') r = input[i+2];
                else if (input[i] == 'o') o = input[i+2];
                else if (input[i] == 'y') y = input[i+2];
                else if (input[i] == 'g') g = input[i+2];
                else b = input[i+2];
            }
            s += r; s += o; s += y; s += g; s += b;
            bin.push_back(s);
        }
    }
}
