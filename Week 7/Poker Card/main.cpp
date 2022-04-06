#include <iostream>
#include <cstdlib>

class PokerCard
{
public:
  PokerCard(std::string s, int f)
  {
    suit = s;
    face = f;
  }
  friend std::ostream &operator<<(std::ostream &out, const PokerCard &p)
  {
    out << "[" << p.face << " of " << p.suit << "]";
    return out;
  }

  /*
  suit: spade > heart > diamond > club
  face: 1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
  
    if (a.face > b.face)
      => a > b;
    else if (a.face == b.face)
    {
        if (a.suit > b.suit)
          => a > b;
        else
          => b > a;
    }
    else
      => b > a;
  */
  
  bool operator>(PokerCard &b)
  {
    // code here
  }
  bool operator<(PokerCard &b)
  {
    // code here
  }
  bool operator==(PokerCard &b)
  {
    // code here
  }

private:
  std::string suit;
  int face;
};

int main()
{
  PokerCard **card = (PokerCard **)malloc(sizeof(PokerCard *) * 52);

  std::string s[] = {"spade", "heart", "diamond", "club"};
  int j, k;
  for (j = 0; j < 4; j++)
    for (k = 1; k <= 13; k++)
      card[j * 13 + k - 1] = new PokerCard(s[j], k);
  for (j = 0; j < 52; j++)
  {
    for (k = 0; k < 52; k++)
    {
      std::cout << *(card[j]) << ">" << *(card[k]) << ":" << (*(card[j]) > *(card[k])) << std::endl;
      std::cout << *(card[j]) << "<" << *(card[k]) << ":" << (*(card[j]) < *(card[k])) << std::endl;
      std::cout << *(card[j]) << "==" << *(card[k]) << ":" << (*(card[j]) == *(card[k])) << std::endl;
    }
  }
}
