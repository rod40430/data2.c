#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
  int age;  // 나이
  char name[50];  // 이름
public:
  Person(int myage, char * myname) : age(myage)
  {
    strcpy(name, myname);
  }
  void WhatYourName() const
  {
    cout<<"My name is "<<name<<endl;
  }
  void HowOldAreyou() const
  {
    cout<<"I'm "<<age<<" years old"<<endl;
  }
};

class UnivStudent : public Person
{
private:
  char major[50];  // 전공과목
public:
  UnivStudent(char * myname, int myage, char * myjor)
    :Person(myage, myname)
  {
    strcpy(major, myjor);
  }
  void WhoAreYou() const
  {
    WhatYourName();
    HowOldAreyou();
    cout<<"My major is "<<major<<endl<<endl;
  }
};

int main(void)
{
  UnivStudent ustd1("Lee", 22, "Computer eng");
  ustd1.WhoAreYou();

  UnivStudent ustd2("Yoon", 21, "Electronic eng");
  ustd2.WhoAreYou();

  return 0;
}
