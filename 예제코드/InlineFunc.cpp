// InlineFunc.cpp -- C++ 기반의 인라인 함수 정의
#include <iostream>

inline int SQUARE(int x)
{
  return x * x;
}

int main(void)
{
  std:: cout<< SQUARE(5)<< std:: endl;
  std:: cout<< SQUARE(12)<< std:: endl;

  return 0;
}
