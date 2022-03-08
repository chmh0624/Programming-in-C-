#include <iostream>
#include <vector>

std::vector <char> data;

int find(char s)
{
    for (int i=0; i<data.size(); i++)
    {
        if (data[i] == s)
            return i;
    }
    return -1;
}

int max(int a, int b)
{
    return (a>b) ? a : b;
}

int main()
{
    std::string str;
    std::getline(std::cin, str);
    int maxLen = 0;
    
    for (int i=0; i<str.length(); i++)
    {
        int index = find(str[i]);
        data.push_back(str[i]);
        maxLen = max(max(maxLen, index+1), data.size()-index-1);
        if (index != -1)
            for (int i=0; i<=index; i++)
                data.erase(data.begin());
    }
    std::cout << maxLen << std::endl;
}
