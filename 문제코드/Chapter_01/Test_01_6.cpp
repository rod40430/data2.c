// 문제 01 - 6 [C++ 기반의 데이터 입출력]
#include <iostream>

int BoxVolume(int length, int width = 1, int height = 1);

int main(void)
{
  std:: cout<< "[3, 3, 3] : "<< BoxVolume(3, 3, 3)<< std:: endl;
  std:: cout<< "[5, 5, D] : "<< BoxVolume(5, 5)<< std:: endl;
  std:: cout<< "[7, D, D] : "<< BoxVolume(7)<< std:: endl;
  // std:: cout<< "[D, D, D] : "<< BoxVolume()<< std:: endl;

  return 0;
}

int BoxVolume(int length, int width, int heigth)
{
  return length * width * heigth;
}
int BoxVolume(int length, int width)
{
  return length * width;
}
int BoxVolume(int length)
{
  return length;
}
