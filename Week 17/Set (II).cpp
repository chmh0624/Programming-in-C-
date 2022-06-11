template <typename T>
class Set
{
  public:
    Set()
    {
        count = 0;
        for (int i=0; i<100; i++)
            element[i] = 0; 
    }
    Set(Set &s)
    {
        count = s.count;
        for (int i=0; i<100; i++)
            element[i] = s.element[i]; 
    }
    int add(const T n)
    {
        for (int i=0; i<count; i++)
            if (element[i] == n)
              return 0;
        element[count++] = n;
        return 1;
    }

    int add(const Set s)
    {
        int sum = 0;
        for (int i=0; i<s.count; i++)
        {
          bool flag = true;
            for (int j=0; j<count && flag; j++)
            {
              if (s.element[i] == element[j])
                flag = false;
            }
          if (flag){
            element[count ++] = s.element[i];
            sum ++;
          }
        }
      return sum;
    }
    void display()
    {
        int j;
        for(j = 0;j < count;j ++)
            std::cout<<element[j]<<" ";
    }
  private:
    T element[100];
    int count;
};


