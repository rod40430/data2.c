#include <iostream>
#include <cstring>

using namespace std;

class Empolyee
{
private:
  char name[100];
public:
  Empolyee(char * name)
  {
    strcpy(this->name, name);
  }

  void ShowYourName() const
  {
    cout<<"name : "<<name<<endl;
  }
};

class PermanentWorker : public Empolyee
{
private:
  int Salary;  // 월 급여
public:
  PermanentWorker(char * name, int money)
    : Empolyee(name), Salary(money)
  {}

  int Getpay() const {return Salary;}
  void ShowSalaryInfo() const
  {
    ShowYourName();
    cout<<"Salary : "<<Getpay()<<endl<<endl;
  }
};

class EmpolyeeHandler
{
private:
  Empolyee * empList[50];
  int empNum;
public:
  EmpolyeeHandler() : empNum(0)
  {}

  void AddEmployee(Empolyee * emp)
  {
    empList[empNum++] = emp;
  }
  void ShowAllSalaryInfo() const
  {
    // for (int i = 0; i <empNum; i++)
    //   empList[i]->ShowSalaryInfo();
  }
  void ShowTotalSalary() const
  {
    int sum = 0;

    // for (int i = 0; i < empNum; i++)
    //   sum += empList[i]->GetPay();
    cout<<"Salary sum : "<<sum<<endl;
  }
  ~EmpolyeeHandler()
  {
    for (int i = 0; i < empNum; i++)
      delete empList[i];
  }
};

int main(void)
{
  // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
  EmpolyeeHandler handler;

  // 직원 등록
  handler.AddEmployee(new PermanentWorker("KIM", 1000));
  handler.AddEmployee(new PermanentWorker("LEE", 1500));
  handler.AddEmployee(new PermanentWorker("JUN", 2000));

  // 이번 달에 지불해야 할 급여의 정보
  handler.ShowAllSalaryInfo();

  // 이번 달에 지불해야 할 급여의 총합
  handler.ShowTotalSalary();

  return 0;
}
