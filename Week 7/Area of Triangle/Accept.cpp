double getArea()
{
  double a = sqrt(pow((point[0].x - point[1].x), 2) + pow((point[0].y - point[1].y), 2));
  double b = sqrt(pow((point[2].x - point[1].x), 2) + pow((point[2].y - point[1].y), 2));
  double c = sqrt(pow((point[0].x - point[2].x), 2) + pow((point[0].y - point[2].y), 2));
  double s = (a + b + c) / 2;
  return sqrt(s * (s-a) * (s-b) * (s-c));
}

double operator + (Triangle &t)
{
  return getArea() + t.getArea();
}
