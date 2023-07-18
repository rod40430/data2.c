#include <iostream>
#define FUNC_MAX 4

using namespace std;

typedef class Calculator
{
private:
  int count[FUNC_MAX] = {0, };

public:
  // void Init();
  double Add(double num1, double num2);
  double Min(double num1, double num2);
  double Mul(double num1, double num2);
  double Div(double num1, double num2);
  void ShowOpCount();

} cal;

int main(void)
{
  cal cal;
  
  // cal.Init();
  cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
  cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
  cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
  cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
  cal.ShowOpCount();

  return 0;
}


// void cal::Init()
// {
//   count[FUNC_MAX] = {0, };
// }

double cal::Add(double num1, double num2)
{
  count[0]++;
  return num1 + num2;
}

double cal::Min(double num1, double num2)
{
  count[1]++;
  return num1 - num2;
}

double cal::Mul(double num1, double num2)
{
  count[2]++;
  return num1 * num2;
}

double cal::Div(double num1, double num2)
{
  count[3]++;
  return num1 / num2;
}

void cal::ShowOpCount()
{
  cout<<"덧셈 : "<<count[0]<<' ';
  cout<<"뺄셈 : "<<count[1]<<' ';
  cout<<"곱셈 : "<<count[2]<<' ';
  cout<<"나눗셈 : "<<count[3]<<' '<<endl;
}
