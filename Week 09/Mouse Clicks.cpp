#include <iostream>
#include <vector>
#include <iomanip>

typedef struct Point
{
    Point(){}
    Point(int _x, int _y){ x = _x; y = _y; }
    int x, y;
}Point;

typedef struct Rect
{
    Rect(){}
    Rect(Point _p1, Point _p2){ p1 = _p1; p2 = _p2; }
    Point p1, p2;
}Rect;

std::vector <Point> icon;
std::vector <Point> ms;
std::vector <Rect> region;

bool inRect(Rect r, Point p)
{
    return (p.x >= r.p1.x && p.x <= r.p2.x && p.y <= r.p2.y && p.y >= r.p1.y);
}

int sqDict(Point p1, Point p2)
{
    return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main()
{
    char type;
    int x1, x2, y1, y2;
    while (std::cin >> type && type != '#')
    {
        if (type == 'I')
        {
            std::cin >> x1 >> y1;
            icon.push_back(Point(x1, y1));
        }
        else if (type == 'R')
        {
            std::cin >> x1 >> y1 >> x2 >> y2;
            region.push_back(Rect(Point(x1, y1), Point(x2, y2)));
        }
        else
        {
            std::cin >> x1 >> y1;
            ms.push_back(Point(x1, y1));
        }
    }
    // remove no-used icon
    for (int i=0; i<icon.size(); i++)
    {
        for (int j=0; j<region.size(); j++)
        {
            if (inRect(region[j], icon[i]))
            {
                icon[i].x += 1000;
                break;
            }
        }
    }
    // mouse click event
    for (int i=0; i<ms.size(); i++)
    {
        bool notFound = true;
        // inside rect.
        for (int j=region.size()-1; j>=0 && notFound; j--)
        {
            if (inRect(region[j], ms[i]))
            {
                std::cout << (char)('A'+j) << std::endl;
                notFound = false;
            }
        }
        if (!notFound)
            continue;
        std::vector <int> near;
        int min = 1000000;
        for (int j=0; j<icon.size(); j++)
        {
            if (sqDict(ms[i], icon[j]) == min)
            {
                near.push_back(j+1);
            }
            else if (sqDict(ms[i], icon[j]) < min)
            {
                near.clear();
                near.push_back(j+1);
                min = sqDict(ms[i], icon[j]);
            }
        }
        for (int j=0; j<near.size(); j++)
            std::cout << std::setw(3) << near[j];
        std::cout << std::endl;
    }
}
