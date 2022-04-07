int findSuit(std::string target)
{
  std::string _suit[4] = {"club", "diamond", "heart", "spade"};
  for (int i=0; i<4; i++)
    if (_suit[i] == target)
      return i;
}

int findFace(int target)
{
  int _face[13] = {2,3,4,5,6,7,8,9,10,11,12,13,1};
  for (int i=0; i<13; i++)
    if (_face[i] == target)
      return i;
}

bool operator>(PokerCard &b)
{
  int mySuitID = findSuit(suit);
  int myFaceID = findFace(face);
  int bSuitID = findSuit(b.suit);
  int bFaceID = findFace(b.face);
  if (myFaceID > bFaceID)
    return true;
  else if (myFaceID < bFaceID)
    return false;
  else
  {
    if (mySuitID > bSuitID)
      return true;
    return false;
  }
}

bool operator<(PokerCard &b)
{
  int mySuitID = findSuit(suit);
  int myFaceID = findFace(face);
  int bSuitID = findSuit(b.suit);
  int bFaceID = findFace(b.face);
  if (myFaceID < bFaceID)
    return true;
  else if (myFaceID > bFaceID)
    return false;
  else
  {
    if (mySuitID < bSuitID)
      return true;
    return false;
  }
}

bool operator==(PokerCard &b)
{
  return (suit == b.suit && face == b.face);
}
