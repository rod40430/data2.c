// 문제 01 - 3 [C++ 기반의 데이터 입출력]
#include <iostream>

int main(void)
{
  int num;

  std:: cout<< "원하는 구구단 숫자 입력 : ";
  std:: cin>> num;

  for (int i = 1; i <= 9; i++)
    std:: cout<< num<< " x "<< i<< " = "<< num * i<< std:: endl;

  return 0;
}
