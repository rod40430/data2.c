// UsingDcl3.cpp -- 이름공간 std에 선언된 모든것에 대해 이름공간 지정의 생략
#include <iostream>

using namespace std;

int main(void)
{
  int num = 20;
  cout<< "Hello World!"<< endl;
  cout<< "Hello "<< "World!"<< endl;
  cout<< num<< ' '<< 'A';
  cout<< ' '<< 3.14<< endl;
}
