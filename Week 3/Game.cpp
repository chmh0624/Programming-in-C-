class Player
{
    public:
        Player()
        {

        }
        Player(int num, std::string name)
        {
          	number = num;
          	name = name;
            if (num <= 0 && num >= 5)
                std::cerr << "out of range\n";
          	int isLegal = (name.length() < 20);
          	
            for (int i=0; i<name.length() && isLegal; i++)
            {
            	if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z')))
            	{
            		isLegal = 0;
            		break;
            	}
            }
          	if (isLegal == 0) std::cerr << "your name is illegal\n";
        }
        int getPlayerNum()
        {
            return number;
        }

        std::string getPlayerName()
        {
            return name;
        }

        bool setPlayerNum(int n)
        {
            if (n > 0 && n < 5){
                number = n;
                return true;
            }
            return false;
        }

        bool setPlayerName(std::string n)
        {
        	int len = n.length();
        	if (len >= 20)
        		return false;
        	for (int i=0; i<len; i++)
        	{
        		if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z')))
            	{
            		return false;
            	}
        	}
            name = n;
            return true;
        }
    private:
        int number;
        std::string name;

};
