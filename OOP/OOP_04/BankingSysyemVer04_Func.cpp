#include "BankingSystemVer04.hpp"
#include <iostream>
#include <cstring>

using namespace std;

void ShowMenu() {
  cout << "-----Menu-----" << endl;
  cout << "1. 계좌개설" << endl;
  cout << "2. 입금" << endl;
  cout << "3. 출금" << endl;
  cout << "4. 계좌정보 전체 출력" << endl;
  cout << "5. 프로그램 종료" << endl;
  cout << "선택 : ";
}

User::User(int id, int cash, char * name)
    :userid(id), ucash(cash)
{
  uname = new char[strlen(name) + 1];
  strcpy(uname, name);
}

User::User(const User &copy)
  : userid(copy.userid), ucash(copy.ucash)
{
  uname = new char[strlen(copy.uname) + 1];
  strcpy(uname, copy.uname);
}

void CreateAccount(User **user, int i) {
  int id;
  int cash;
  char name[MAX_STR];
  
  cout << "[계좌개설]" << endl;
  cout << "계좌ID : ";
  cin >> id;
  cout << "이름 : ";
  cin >> name;
  cout << "입금액 : ";
  cin >> cash;
  cout << endl;

  user[i] = new User(id, cash, name);
}

int User::GetID(void) const
{
  return userid;
}

void User::InCash(int money)
{
  ucash += money;
}

void InCash(User *user, int count) {
  int id;
  int money;

  cout << "[입 금]" << endl;
  cout << "계좌ID : ";
  cin >> id;

  for (int i = 0; i < count; i++) {
    if (user[i].GetID() == id)
    {
      cout << "입금액 : ";
      cin >> money;
      user[i].InCash(money);
      cout << "입금완료" << endl<<endl;
    } else {
      cout << "계좌가 존재하지않습니다." << endl;
    }
  }
}

int User::OutCash(int money)
{
  if (ucash < money)
    return 0;

  ucash -= money;
  return money;
}

void OutCash(User *user, int count) {
  int id;
  int money;

  cout << "[출 금]" << endl;
  cout << "계좌ID : ";
  cin >> id;

  for (int i = 0; i < count; i++) {
    if (user[i].GetID() == id) 
    { 
      cout << "출금액 : ";
      cin >> money;
      
      if (user[i].OutCash(money) == 0)
      {
        cout<<"잔액부족"<<endl;
        return;
      }
      cout << "출금완료" << endl<<endl;
    } else {
      cout << "계좌가 존재하지않습니다." << endl;
    }
  }
}

void User::ShowAccount() const
{
  cout << "계좌ID : " << this->userid << endl;
  cout << "이름 : " << this->uname << endl;
  cout << "잔액 : " << this->ucash << endl<<endl;
}

void ShowAccount(User *user, int count) {
  for (int i = 0; i < count; i++) {
    if (user[i].GetID() != 0) {
      user[i].ShowAccount();
    } else {
      cout << endl << "계좌가 존재하지 않습니다." << endl<<endl;
    }
  }
}

User::~User()
{
  delete []uname;
}