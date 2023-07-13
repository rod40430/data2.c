#include <iostream>

using namespace std;

void add(int &a)
{
  a++;
}

void reverse(int &a)
{
  a *= -1;
}

int main(void)
{
  int a;
  
  cout<<"수 입력 : ";
  cin>>a;
  cout<<endl;
  
  cout<<a<<endl;
  add(a);
  cout<<a<<endl;
  reverse(a);
  cout<<a<<endl;
  reverse(a);
  cout<<a<<endl;
}
