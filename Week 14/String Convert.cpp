class Convert
{
private:
    std::string str;

public:
    Convert() {}
    Convert(std::string s) { str = s; }
    int toInt()
    {
        return stoi(str);
    }
    double toDouble()
    {
        return stod(str);
    }
};
