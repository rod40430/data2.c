// 문제 01 - 1 [C++ 기반의 데이터 입출력]
#include <iostream>

int main(void)
{
  int val[5];
  int value = 0;

  for (int i = 0; i < 5; i++)
    {
      std:: cout<< i + 1<< "번째 정수 입력 : ";
      std:: cin>> val[i];;     

      value += val[i];
    }

  std:: cout<< "합계 : "<< value;
  
  return 0;
}
