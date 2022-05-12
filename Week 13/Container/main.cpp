#include <bits/stdc++.h>
using namespace std;

class Container
{
public:
    Container()
    {
        index = 0;
    }
    void insert(int n)
    {
        if(n >= 0)
        {
            data[index] = n;
            index ++;
        }
    }
    virtual int remove() = 0;  //remove an element from container
    void display()
    {
        int j;
        if(index == 0)
            return;
        for(j = 0; j < index - 1; j ++)
            cout<<data[j]<<", ";
        cout<<data[j];
    }
protected:
    int data[100];
    int index;
};

class RemoveFromBig: public Container
{
	int remove()
	{
		int big = data[0], bigidx = 0;
		for (int i=0; i<index; i++)
		{
			if (data[i] > big)
			{
				big = data[i];
				bigidx = i;
			}
		}
		for (int i=bigidx+1; i<index; i++)
			data[i-1] = data[i];
		index --;
		return big;
	}
};

class RemoveFromSmall: public Container
{
	int remove()
	{
		int small = data[0], smallidx = 0;
		for (int i=0; i<index; i++)
		{
			if (data[i] < small)
			{
				small = data[i];
				smallidx = i;
			}
		}
		for (int i=smallidx+1; i<index; i++)
			data[i-1] = data[i];
		index --;
		return small;
	}
};

int main()
{
	
}
