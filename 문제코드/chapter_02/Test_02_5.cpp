#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
  char str[] = "Hello";
  char copy[20];

  strcpy(copy, str);
  cout<<"str : "<<str<<endl;
  cout<<"copy : "<<copy<<endl;
  if (strcmp(str, copy) == 0)
  {
    cout<<"str와 copy는 같다."<<endl;
  }
  else
  {
    cout<<"str와 copy는 다르다."<<endl;
  }
  strcat(copy, " World!");
  cout<<"str : "<<str<<endl;
  cout<<"copy : "<<copy<<endl;
  if (strcmp(str, copy) == 0)
  {
    cout<<"str와 copy는 같다."<<endl;
  }
  else
  {
    cout<<"str와 copy는 다르다."<<endl;
  }
  cout<<"str의 문자열길이 : "<<strlen(str)<<endl;
  cout<<"copy의 문자열길이 : "<<strlen(copy)<<endl;

  return 0;
}
