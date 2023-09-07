#include <iostream>
using namespace std;

class SoSimple
{
public:
  virtual void ShowSimpleInfo()
  {
    cout<<"SoSimple Base Class"<<endl;
  }
};

class SoComplex : public SoSimple
{
public:
  void ShowSimpleInfo() //  이것 역시 가상함수
  {
    cout<<"SoComplex Derived Class"<<endl;
  }
};

int main(void)
{
  SoSimple * simPtr = new SoComplex;
  SoComplex * comPtr = dynamic_cast<SoComplex*>(simPtr);
  comPtr->ShowSimpleInfo();

  return 0;
}