#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
  try
    {
      if (num2 == 0)
        throw 0;
      cout<<"몫 : "<<num1 / num2<<endl;
      cout<<"나머지 : "<<num1 % num2<<endl;
    }
    catch(int expn)
    {
      cout<<"first catch"<<endl;
      throw;  // 예외를 다시 던진다.
    }
}

int main(void)
{
  try
    {
      Divide(9, 2);
      Divide(4, 0);
    }
    catch(int expn)
    {
      cout<<"Second catch"<<endl;
    }
    catch(...)
    {
      cout<<"...은 전달되는 모든 예외를 다 받아주겠다는 선언(catch블록에 덧붙이는 경우가 많음)"            <<endl;
    }

  return 0;
}