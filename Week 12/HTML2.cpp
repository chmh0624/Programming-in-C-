/*
  NOTE: The List Has To Be Sorted.
*/

class HTMLElementWithAttributes : HTMLElement
{
public:
    HTMLElementWithAttributes(std::string str) : HTMLElement(str)
    {
        for (int i = 1+getTagName().size(); str[i] != '>'; i++)
        {
            std::string key = "", value = "";
            for (i++; str[i]!='='; i++)
                key += str[i];
            for (i+=2; str[i]!='"'; i++)
                value += str[i];
            attributes[key] = value;
            myList.push_back(key);
        }
        myList.sort();
    }
    std::string getTagName()
    {
        return HTMLElement::getTagName();
    }
    std::string getContent()
    {
        return HTMLElement::getContent();
    }
    std::list<std::string> getAttributes()
    {
        return myList;
    }
    std::string operator[](std::string key) 
    { 
    	return attributes[key]; 
    }

private:
    std::map<std::string, std::string> attributes;
    std::list <std::string> myList;
};
int main() {
  std::string str;
  getline(std::cin,str);
  HTMLElementWithAttributes html(str);
  std::cout << html.getTagName() << endl ;
  std::list<std::string> key = html.getAttributes();
  for(std::string k : key)
    std::cout<<html[k]<<std::endl;
  return 0;
}

