// InlineFunc+.cpp -- C++ 기반의 인라인 함수 정의 + 템플릿
#include <iostream>

template <typename T>

inline T SQUARE(T x)
{
  return x * x;
}

int main(void)
{
  std:: cout<< SQUARE(5.5)<< std:: endl;
  std:: cout<< SQUARE(12)<< std:: endl;

  return 0;
}
