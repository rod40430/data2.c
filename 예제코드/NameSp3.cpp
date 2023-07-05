// NameSp3.cpp -- namespace의 사용
#include <iostream>

namespace BestComImp1
{
  void SimpleFunc(void);
}

namespace BestComImp1
{
  void PrettyFunc(void);
}

namespace ProgComImp1
{
  void SimpleFunc(void);
}

int main(void)
{
  BestComImp1::SimpleFunc();

  return 0;
}

void BestComImp1:: SimpleFunc(void)
{
  std:: cout<< "BestCom이 정의한 함수"<< std:: endl;
  PrettyFunc();  // 동일 이름공간
  ProgComImp1:: SimpleFunc();  // 다른 이름공간
}

void BestComImp1:: PrettyFunc(void)
{
  std:: cout<< "So Pretty!!"<< std:: endl;
}

void ProgComImp1:: SimpleFunc(void)
{
  std:: cout<< "ProgCom이 정의한 함수"<< std:: endl;
}
