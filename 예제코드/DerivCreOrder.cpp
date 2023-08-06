#include <iostream>

using namespace std;

class SoBase
{
private:
  int baseNum;
public:
  SoBase() : baseNum(20)
  {
    cout<<"SoBase()"<<endl;
  }
  SoBase(int n) : baseNum(n)
  {
    cout<<"SoBase(int n)"<<endl;
  }
  void ShowBaseData()
  {
    cout<<baseNum<<endl;
  }
};

class SoDerived : public SoBase
{
private:
  int derivNum;
public:
  SoDerived() : derivNum(20)
  {
    cout<<"SoDerived()"<<endl;
  }
  SoDerived(int n) : derivNum(n)
  {
    cout<<"SoDerived(int n)"<<endl;
  }
  SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
  {
    cout<<"SoDerived(int n1, int n2)"<<endl;
  }
  void ShowDerivedData()
  {
    ShowBaseData();
    cout<<derivNum<<endl;
  }
};

int main(void)
{
  cout<<"case1....."<<endl;
  SoDerived dr1;
  dr1.ShowDerivedData();
  cout<<"--------------------"<<endl;
  cout<<"case2....."<<endl;
  SoDerived dr2(12);
  dr2.ShowDerivedData();
  cout<<"--------------------"<<endl;
  cout<<"case3....."<<endl;
  SoDerived dr3(23, 24);
  dr3.ShowDerivedData();

  return 0;
}
