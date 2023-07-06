// NameAlias.cpp -- namespace에 별칭을 줄 수 있다.
#include <iostream>

using namespace std;

namespace AAA
{
  namespace BBB
  {
    namespace CCC
    {
      int num1;
      int num2;
    }
  }
}

int main(void)
{
  AAA::BBB::CCC::num1 = 20;
  AAA::BBB::CCC::num2 = 30;

  namespace ABC = AAA::BBB::CCC;
  cout<<ABC::num1<<endl;
  cout<<ABC::num2<<endl;

  return 0;
}
