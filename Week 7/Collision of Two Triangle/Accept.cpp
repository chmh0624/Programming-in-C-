/*
  Point p, q, r
  
                 | p.x q.x r.x p.x |
  Area =  0.5 x ||                 ||
                 | p.y q.y r.y p.y |
*/

float getArea(Point p, Point q, Point r)
{
    float a = sqrt(pow((p.x - q.x), 2) + pow((p.y - q.y), 2));
    float b = sqrt(pow((p.x - r.x), 2) + pow((p.y - r.y), 2));
    float c = sqrt(pow((r.x - q.x), 2) + pow((r.y - q.y), 2));
    float s = (a+b+c)/2;
    return 0.5*abs((p.x*q.y+q.x*r.y+r.x*p.y)-(p.y*q.x+q.y*r.x+r.y*p.x));
}

bool operator *(Triangle &t)
{
    for (int i=0; i<3; i++)
    {
        float area1 = getArea(t.point[i], point[0], point[1]);
        float area2 = getArea(t.point[i], point[2], point[1]);
        float area3 = getArea(t.point[i], point[0], point[2]);
        if (area1 + area2 + area3 == getArea(point[0], point[1], point[2]))
            return true;
    }
    for (int i=0; i<3; i++)
    {
        float area1 = getArea(point[i], t.point[0], t.point[1]);
        float area2 = getArea(point[i], t.point[2], t.point[1]);
        float area3 = getArea(point[i], t.point[0], t.point[2]);
        if (area1 + area2 + area3 == getArea(t.point[0], t.point[1], t.point[2]))
            return true;
    }
    return false;
}
