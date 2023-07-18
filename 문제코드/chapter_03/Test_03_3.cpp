#include <iostream>
#include <cstring>

using namespace std;

typedef class Printer
{
private:
  char copy[20];

public:
  void SetString(char *ch);
  void ShowString();

} pnt;

int main(void)
{
  pnt pnt;

  pnt.SetString("Hello world!");
  pnt.ShowString();

  pnt.SetString("I love C++");
  pnt.ShowString();

  return 0;
}

void pnt::SetString(char *ch)
{
  strcpy(copy, ch);
}

void pnt::ShowString()
{
  cout<<copy<<endl;
}
