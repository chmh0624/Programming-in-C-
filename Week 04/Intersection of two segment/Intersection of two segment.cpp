Segment(Coordinate _a, Coordinate _b)
{
  a.setX(_a.getX());
  a.setY(_a.getY());
  b.setX(_b.getX());
  b.setY(_b.getY());
}

int XFromA() { return getCoordinateA().getX(); }
int YFromA() { return getCoordinateA().getY(); }
int XFromB() { return getCoordinateB().getX(); }
int YFromB() { return getCoordinateB().getY(); }

float dist(Coordinate c1, Coordinate c2)
{
  int deltaX = c1.getX() - c2.getX();
  int deltaY = c1.getY() - c2.getY();
  return sqrt(deltaX * deltaX + deltaY * deltaY);
}

Coordinate *isSamePoint(Coordinate c1, Coordinate c2, Coordinate s1, Coordinate s2)
{
  Coordinate *samePoint = new Coordinate;
  if (dist(c1, s1) == 0)
      *samePoint = Coordinate(c1);
  else if (dist(c1, s2) == 0)
      *samePoint = Coordinate(c1);
  else if (dist(c2, s1) == 0)
      *samePoint = Coordinate(c2);
  else if (dist(c2, s2) == 0)
      *samePoint = Coordinate(c2);
  else
      samePoint = NULL;
  return samePoint;
}

Coordinate *getIntersection(Segment S)
{
  // Same Point?
  Coordinate *samePoint = isSamePoint(a, b, S.getCoordinateA(), S.getCoordinateB());
  if (samePoint != NULL)
      return samePoint;

  float mySlopeY = YFromA() - YFromB();
  float mySlopeX = XFromA() - XFromB();
  float sSlopeY = S.YFromA() - S.YFromB();
  float sSlopeX = S.XFromA() - S.XFromB();
  // Parallel?
  if ((mySlopeX == 0 && sSlopeX == 0) || mySlopeY * sSlopeX == sSlopeY * mySlopeX)
      return NULL;
  else
  {
      float interX ,interY;
      float coefficient[2][3] = {mySlopeY, (-1) * mySlopeX, mySlopeY * XFromA() - mySlopeX * YFromA(), sSlopeY, (-1) * sSlopeX, sSlopeY * S.XFromA() - sSlopeX * S.YFromA()};
      if (mySlopeX == 0)
      {
          interX = coefficient[0][2] / coefficient[0][0];
          interY = (coefficient[1][2] - coefficient[1][0] * interX) / coefficient[1][1];
      }
      else if (sSlopeX == 0)
      {
          interX = coefficient[1][2] / coefficient[1][0];
          interY = (coefficient[0][2] - coefficient[0][0] * interX) / coefficient[0][1];
      }
      else if (mySlopeY == 0)
      {
          interY = coefficient[0][2] / coefficient[0][1];
          interX = (coefficient[1][2] - coefficient[1][1] * interY) / coefficient[1][0];
      }
      else if (sSlopeY == 0)
      {
          interY = coefficient[1][2] / coefficient[1][1];
          interX = (coefficient[0][2] - coefficient[0][1] * interY) / coefficient[0][0];
      }
      else
      {
          // Augmented Matrix of Two Linear Equation
          float coefficient[2][3] = {mySlopeY, mySlopeX, mySlopeY * XFromA() - mySlopeX * YFromA(), sSlopeY, sSlopeX, sSlopeY * S.XFromA() - sSlopeX * S.YFromA()};
          // Gauss Elimination
          for (int i=0; i<3; i++)
              coefficient[1][i] = coefficient[1][i] * (-1) * (mySlopeY * sSlopeX) / (mySlopeX * sSlopeY) + coefficient[0][i];
          // Back Substitution
          interY = coefficient[1][2] / coefficient[1][1];
          interX = (coefficient[0][2] - coefficient[0][1] * interY) / coefficient[0][0];
      }
      Coordinate *inter = new Coordinate;
      *inter = Coordinate(interX, interY);
      float inter2Sa = dist(S.getCoordinateA(), *inter);
      float inter2Sb = dist(S.getCoordinateB(), *inter);
      float inter2a = dist(a, *inter);
      float inter2b = dist(b, *inter);
      float lengthOfS = dist(S.getCoordinateA(), S.getCoordinateB());
      if (inter2Sa > lengthOfS || inter2Sb > lengthOfS || inter2a > length() || inter2b > length())
          return NULL;
      else
          return inter;
  }
}

float length() // return the length of segment
{
  return dist(a, b);
}
