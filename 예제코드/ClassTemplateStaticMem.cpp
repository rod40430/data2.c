#include <iostream>
using namespace std;

template <typename T>
class SimplestaticMem
{
private:
  static T mem;
public:
  void AddMem(T num) {mem += num;}
  void ShowMem() {cout<<mem<<endl;}
};

template <typename T>
T SimplestaticMem<T>::mem = 0;  // static 멤버의 초기화 문장!

int main(void)
{
  SimplestaticMem<int> obj1;
  SimplestaticMem<int> obj2;
  obj1.AddMem(2);
  obj2.AddMem(3);
  obj1.ShowMem();
  
  SimplestaticMem<long> obj3;
  SimplestaticMem<long> obj4;
  obj3.AddMem(100);
  obj4.ShowMem();

  return 0;
}