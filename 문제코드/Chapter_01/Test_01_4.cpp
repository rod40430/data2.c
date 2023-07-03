// 문제 01 - 4 [C++ 기반의 데이터 입출력]
#include <iostream>

int main(void)
{
  int value = 50;
  double a = 0.12;

  for (int cash; cash != -1;)
    {
      cash = 0;
      
      std:: cout<< "판매 금액을 만원 단위로 입력 (-1 to end) : ";
      std:: cin>> cash;

      if (cash != -1)
        std:: cout<< "이번 달 급여 : "<< value + cash * a<< "만원"<< std:: endl;
    }

  std:: cout<< "프로그램을 종료합니다."<< std:: endl;
  
  return 0;
}
