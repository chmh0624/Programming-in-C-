/*
  Input: <tag> this symbol <> means a pair of bracket </tag> 
*/

#include <iostream>
class HTMLElement
{
    public:
        std::string tagName, content;
        HTMLElement(std::string str)
        {
            int i, bracket;
            for (i=1; i<str.length() && str[i]!='>'; i++)
                tagName += str[i];
            for (bracket=str.length()-1; str[bracket]!='<'; bracket--);
            for (i=i+1; i<bracket; i++)
                content += str[i];
                
        }
        std::string getTagName()
        {
            return tagName;
        }
        std::string getContent()
        {
            return content;
        }
};
int main() {
    std::string str;
    getline(std::cin, str);
    HTMLElement html(str);
    std::cout<<html.getTagName()<<std::endl;
    std::cout<<html.getContent()<<std::endl;
    return 0;
}
