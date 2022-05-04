#include <iostream>
#include <sstream>

class Convert
{
    public:
        std::string toString(int n)
        {
            std::string tmp;
            tmp += (char)((n%10)+'0');
            if (n/10 > 0)
                return toString(n/10) + tmp;
            else
                return tmp;
        }
        std::string toString(float f)
        {
            std::string s;
            std::stringstream ss;
            ss << f;
            ss >> s;
            return s;
        }

};

int main() {
    int num;
    float f;
    Convert c;
    std::cin >> num;
    std::cout << c.toString(num) << std::endl;
    std::cin >> f;
    std::cout << c.toString(f);
    return 0;
}
