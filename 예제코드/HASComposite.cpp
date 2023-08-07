#include <iostream>
#include <cstring>

using namespace std;

class Gun
{
private:
  int bullet;
public:
  Gun(int bnum) : bullet(bnum)
  {}
  void Shot()
  {
    cout<<"BBANG!"<<endl;
    bullet--;
  }
};

class Pollic
{
private:
  int handcuffs;
  Gun * pistol;
public:
  Pollic(int bnum, int bcuff)
    : handcuffs(bcuff)
  {
    if (bnum > 0)
      pistol = new Gun(bnum);
    else
      pistol = NULL;
  }
  void PutHandcuff()
  {
    cout<<"SNAP!"<<endl;
    handcuffs--;
  }
  void Shot()
  {
    if (pistol == NULL)
      cout<<"Hut BBANG!"<<endl;
    else
      pistol->Shot();
  }
  ~Pollic()
  {
    if (pistol != NULL)
      delete pistol;
  }
};

int main(void)
{
  Pollic pman1(5, 3);
  pman1.Shot();
  pman1.PutHandcuff();

  Pollic pman2(0, 3);
  pman2.Shot();
  pman2.PutHandcuff();

  return 0;
}
