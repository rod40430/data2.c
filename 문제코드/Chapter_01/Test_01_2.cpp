// 문제 01 - 2 [C++ 기반의 데이터 입출력]
#include <iostream>

int main(void)
{
  char name[30];
  char number[11];

  std:: cout<< "이름 입력 : ";
  std:: cin>> name;

  std:: cout<< "전화번호 입력 : ";
  std:: cin>> number;

  std:: cout<< "이름 : "<< name<< std:: endl;
  std:: cout<< "전화번호 : "<< number<< std:: endl;

  return 0;
}
