#include <sstream>
class Convert
{
    public:
        static std::string toString(int n)
        {
        	return std::to_string(n);
        }
        static std::string toString(char c)
        {
        	std::string s;
        	std::stringstream ss;
        	ss << c;
        	ss >> s;
        	return s;
        }
        static std::string toString(double d)
        {
        	std::stringstream ss;
        	std::string str;
        	ss << d;
        	ss >> str;
        	return str;
        }
        static std::string toString(Point p)
        {
        	std::string str = "(";
        	str += std::to_string(p.x);
        	str += ", ";
        	str += std::to_string(p.y);
        	str += ")";
        	return str;
        }
};
