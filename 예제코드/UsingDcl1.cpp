// UsingDcl1.cpp -- using을 이용한 이름공간의 명시
#include <iostream>

namespace Hybrid
{
  void HybFunc(void)
  {
    std:: cout<< "So simple function!"<< std:: endl;
    std:: cout<< "In namespace Hybrid"<< std:: endl;
  }
}

int main(void)
{
  using Hybrid:: HybFunc;
  HybFunc();

  return 0;
}
