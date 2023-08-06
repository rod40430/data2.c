#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
private:
  int age;
  char * name;
public:
  MyFriendInfo(int myage, char * myname) : age(myage)
  {
    name = new char[strlen(myname) + 1];
    strcpy(name, myname);
    cout<<"MyFriendInfo() : "<<name<<" "<<age<<"살"<<endl;
  }
  void ShowMyFriendInfo() const
  {
    cout<<"이름 : "<<name<<endl;
    cout<<"나이 : "<<age<<endl;
  }
  ~MyFriendInfo()
  {
    cout<<"이름 삭제 : "<<name<<endl;
    delete []name;
  }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
  char * addr;
  char * phone;
public:
  MyFriendDetailInfo(char * myname, int myage, char * myaddr, char * myphone)
    : MyFriendInfo(myage, myname)
  {
    addr = new char[strlen(myaddr) + 1];
    phone = new char[strlen(myphone) + 1];
    strcpy(addr, myaddr);
    strcpy(phone, myphone);
    cout<<"MyFriendDetailInfo() : "<<endl;
  }
  void ShowMyFriendDetailInfo()
  {
    ShowMyFriendInfo();
    cout<<"주소 : "<<addr<<endl;
    cout<<"전화 : "<<phone<<endl<<endl;
  }
  ~MyFriendDetailInfo()
  {
    cout<<"주소삭제 : "<<addr<<endl;
    cout<<"전화삭제 : "<<phone<<endl<<endl;
    delete []addr;
    delete []phone;
  }
};

int main(void)
{
  MyFriendDetailInfo fr1("곽태훈", 21, "제주", "010-4444-3333");
  fr1.ShowMyFriendDetailInfo();

  return 0;
}
