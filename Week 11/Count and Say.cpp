#include <iostream>

std::string countAndSay(int n) {
    if (n == 1)
        return "1";
    std::string s = countAndSay(n-1);
    std::string toBeReturn;
    char cur = s[0];
    int cnt = 0;
    for (int i=0; i<s.length(); i++)
    {
        if (cur == s[i])
            cnt ++;
        else
        {
            toBeReturn += std::to_string(cnt);
            toBeReturn += cur;
            cnt = 1;
            cur = s[i];
        }
    }
    toBeReturn += std::to_string(cnt);
    toBeReturn += cur;
    return toBeReturn;
}

int main()
{
    int n;
    while (std::cin >> n)
        std::cout << countAndSay(n) << std::endl;
}
