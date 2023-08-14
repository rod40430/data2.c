#include <iostream>

using namespace std;

class BaseOne
{
public:
  void SimpleFuuncOne() {cout<<"BaseOne"<<endl; }
};

class BaseTwo
{
public:
  void SimpleFuncTwo() {cout<<"BaseTwo"<<endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
  void ComplexFunc()
  {
    SimpleFuuncOne();
    SimpleFuncTwo();
  }
};

int main(void)
{
  MultiDerived mdr;
  mdr.ComplexFunc();

  return 0;
}
