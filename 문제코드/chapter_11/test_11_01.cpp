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
  Pollic(const Pollic& ref)
    : handcuffs(ref.handcuffs)
  {
    if (ref.pistol != NULL)
      pistol = new Gun(*(ref.pistol));
    else
      pistol = NULL;
  }
  Pollic& operator=(const Pollic& ref)
  {
    if (pistol != NULL)
      delete pistol;

    if (ref.pistol != NULL)
      pistol = new Gun(*(pistol));
    else
      pistol = NULL;

    handcuffs = ref.handcuffs;
    return *this;
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
  Pollic pman2 = pman1;  // 복사 생성자의 호출
  pman2.PutHandcuff();
  pman2.Shot();

  Pollic pman3(2, 4);
  pman3 = pman1;  // 대입 연산자의 호출
  pman3.PutHandcuff();
  pman3.Shot();

  return 0;
}
