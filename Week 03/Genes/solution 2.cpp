#include <iostream>
#include <algorithm>

#define D "dominant"
#define R "recessive"
#define N "non-existent"
#define U "unknown"

class Person
{
public:
    std::string name;
    std::string p1Name = U, p2Name = U;
    std::string myGene = U;
};

Person group[3200];
int idx = 0;

bool isValidGene(std::string s) { return (s == D || s == R || s == N); }

int getPosition(std::string _name)
{
    for (int i=0; i<idx; i++)
        if (_name == group[i].name)
            return i;
    return -1;
}

void input()
{
    std::string input1, input2;
    std::cin >> input1 >> input2;
    // name gene
    if (isValidGene(input2))
    {
        group[idx].name = input1;
        group[idx].myGene = input2;
        idx ++;
    }
    // parent child
    else
    {
        int pos = getPosition(input2);
        if (pos == -1)
        {
            group[idx].name = input2;
            group[idx].p1Name = input1;
            idx ++;
        }
        else
        {
            group[pos].p2Name = input1;
        }
    }
}

std::string setGene(int index)
{
    if (group[index].myGene != U)
        return group[index].myGene;
    else
    {
        std::string p1Gene = group[getPosition(group[index].p1Name)].myGene;
        std::string p2Gene = group[getPosition(group[index].p2Name)].myGene;
        if ((p1Gene == D && p2Gene == D) || (p1Gene == D && p2Gene == R) || (p1Gene == R && p2Gene == D))
            return D;
        else if ((p1Gene == R && p2Gene == R) || (p1Gene == D && p2Gene == N) || (p1Gene == N && p2Gene == D))
            return R;
        else
            return N;
    }
}

bool cmp(Person p1, Person p2) { return (p1.name < p2.name); }

int main()
{
    int caseCount;
    std::cin >> caseCount;
    for (int i=0; i<caseCount; i++)
        input();
    for (int i=0; i<idx; i++)
        if (group[i].myGene == U)
            group[i].myGene = setGene(i);
    std::sort(group, group + idx, cmp);
    for (int i=0; i<idx; i++)
        std::cout << group[i].name << " " << group[i].myGene << std::endl;
}
