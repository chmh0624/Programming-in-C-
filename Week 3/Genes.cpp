#include <iostream>

/*
    dominant: 7, recessive: 3, non: 1
    dominant: [++ 14], [+- 10], [+ 7]
    recessive: [+x 8], [- 3], [-- 6]
    non: [x 1], [xx 2], [-x 4]
*/

typedef struct Person
{
    std::string name;
    int parent1, parent2;
    int type;
}Person;

Person person[3100];
int count = 0;

int name2Id(const std::string &name) 
{
    if (name == "dominant") return -1;
    if (name == "recessive") return -2;
    if (name == "non-existent") return -3;

    for (int i = 0; i < count; ++i)
        if (name == person[i].name)
            return i;

    person[count].name = name;
    person[count].type = -100;
    person[count].parent1 = -100;
    person[count].parent2 = -100;
    count++;
    return count-1;
}

int setType(int curId)
{
    int gene1 = 0, gene2 = 0;
    if (person[curId].type == -100)
    {
        if (person[curId].parent1 != -100)
            gene1 = setType(person[curId].parent1);
        if (person[curId].parent2 != -100)
            gene2 = setType(person[curId].parent2);
        if (gene1 + gene2 == 14 || gene1 + gene2 == 10 || gene1 + gene2 == 17)
            return 7;
        else if (gene1 + gene2 == 8 || gene1 + gene2 == 3 || gene1 + gene2 == 6)
            return 3;
        else
            return 1;
    }
    else
    {
        return person[curId].type;
    }
}

int main()
{
    std::string input1, input2;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> input1 >> input2;
        int id1 = name2Id(input1);
        int id2 = name2Id(input2);
        // name type
        if (id2 < 0)
        {
            if (id2 == -1){
                person[id1].type = 7;
            }
            else if (id2 == -2){
                person[id1].type = 3;
            }
            else if (id2 == -3){
                person[id1].type = 1;
            }
        }
        // parent child
        else
        {
            if (person[id2].parent1 == -100)
                person[id2].parent1 = id1;
            else
                person[id2].parent2 = id1;
        }
    }
    for (int i = 0; i < count; ++i)
        if (person[i].type == -100)
            person[i].type = setType(i);
    for (int i=0; i<count; i++)
    {
        int keyIndex = i;
        while (keyIndex > 0 && person[keyIndex - 1].name > person[keyIndex].name)
        {
            Person tmp = person[keyIndex - 1];
            person[keyIndex - 1] = person[keyIndex];
            person[keyIndex] = tmp;
            keyIndex --;
        }
    }
    for (int i=0; i<count; i++)
    {
        std::cout << person[i].name << " ";
        if (person[i].type == 7)
            std::cout << "dominant" << std::endl;
        else if (person[i].type == 3)
            std::cout << "recessive" << std::endl;
        else
            std::cout << "non-existent" << std::endl;
    }

    return 0;
}
