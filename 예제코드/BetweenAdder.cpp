// BetweenAdder.cpp -- 입력 받은 수들 사이에 존재하는 정수들의 합을 구하는 프로그램
#include <iostream>

int main(void)
{
  int val1, val2;
  int result = 0;

  std:: cout<< "두 개의 숫자입력 : ";
  std:: cin>> val1>> val2;

  if (val1 < val2)
  {
    for (int i = val1 +1; i < val2; i++)
      result += i;
  }
  else
  {
    for (int i = val2 + 1; i < val1; i++)
      result += i;
  }

  std:: cout<< "두 수 사이의 정수 합 : "<< result<< std:: endl;

  return 0;
}
