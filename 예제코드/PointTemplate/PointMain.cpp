#include <iostream>
#include "PointTemplate.hpp"
#include "PointTemplate.cpp"  // 헤더파일에 소스를 정의하거나 이런식으로 포함시켜야 실행이 가능하다!!
using namespace std;

int main(void)
{
  Point<int> pos1(3, 4);
  pos1.ShowPosition();

  Point<double> pos2(2.4, 3.6);
  pos2.ShowPosition();

  Point<char> pos3('P', 'F');  // 좌표정보를 문자로 표시하는 상황의 표현
  pos3.ShowPosition();

  return 0;
}