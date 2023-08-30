#include <iostream>

using namespace std;

template <typename T>  // typename이 아닌 class를 사용하여도 된다.
T Add(T num1, T num2)
{
  return num1 + num2;
}

int main(void)
{
  cout<<Add<int>(15, 20)<<endl;
  cout<<Add<double>(2.9, 3.2)<<endl;
  cout<<Add<int>(3.2, 3.2)<<endl;
  cout<<Add<double>(3.14, 2.75)<<endl;

  return 0;
}