#include "BankingSystemVer06.hpp"
#include <iostream>
#include <cstring>

using namespace std;

void UserHandler::ShowMenu(void) const{
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

NormalUser::NormalUser(int id, int cash, char * name, int inter)
    : User(id, cash, name), interest(inter)
  {}

HighCreditUser::HighCreditUser(int id, int cash, char * name, int inter, int cred)
    : NormalUser(id, cash, name, inter), credit(cred)
  {}

UserHandler::UserHandler() : count(0) {};

void UserHandler::CreateAccount(void) {
  int choice;
  int id;
  int cash;
  int inter;
  char name[MAX_STR];

  cout<<"[계좌종류선택]"<<endl;
  cout<<"1 : 보통예금계좌 2 : 신용신뢰계좌"<<endl;
  cout<<"선택 : ";
  cin>>choice;

  if (choice == 1)
  {
    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌ID : ";
    cin >> id;
    cout << "이름 : ";
    cin >> name;
    cout << "입금액 : ";
    cin >> cash;
    cout<<"이자율 : ";
    cin>>inter;
    cout << endl;
    
    user[count++] = new NormalUser(id, cash, name, inter);
  }

  else if (choice == 2)
  {
    int cred;
    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌ID : ";
    cin >> id;
    cout << "이름 : ";
    cin >> name;
    cout << "입금액 : ";
    cin >> cash;
    cout<<"이자율 : ";
    cin>>inter;
    cout<<"신용등급(1toA, 2toB, 3toC) : ";
    cin>>cred;
    if (cred == 1)
      cred = CREDIT::A;
    else if (cred == 2)
      cred = CREDIT::B;
    else if (cred == 3)
      cred = CREDIT::C;
    else
    {
      cout<<"잘못 입력하셨습니다.";
      return ;
    }
    cout << endl;
    
    user[count++] = new HighCreditUser(id, cash, name, inter, cred);
  }
}

int User::GetID(void) const
{
  return userid;
}

void User::InCash(int money)
{
  ucash += money;
}

void NormalUser::InCash(int money)
{
  User::InCash(money);
  User::InCash(money * (interest / 100.0));
}

void HighCreditUser::InCash(int money)
{
  NormalUser::InCash(money);
  User::InCash(money * (credit / 100.0));
}

void UserHandler::InCash(void) {
  int id;
  int money;

  cout << "[입 금]" << endl;
  cout << "계좌ID : ";
  cin >> id;

  for (int i = 0; i < count; i++) {
    if (user[i]->GetID() == id)
    {
      cout << "입금액 : ";
      cin >> money;
      user[i]->InCash(money);
      cout << "입금완료" << endl<<endl;
      return;
    }
  }
  cout << "계좌가 존재하지않습니다." << endl;
}

int User::OutCash(int money)
{
  if (ucash < money)
    return 0;

  ucash -= money;
  return money;
}

void UserHandler::OutCash(void) {
  int id;
  int money;

  cout << "[출 금]" << endl;
  cout << "계좌ID : ";
  cin >> id;

  for (int i = 0; i < count; i++) {
    if (user[i]->GetID() == id) 
    { 
      cout << "출금액 : ";
      cin >> money;
      
      if (user[i]->OutCash(money) == 0)
      {
        cout<<"잔액부족"<<endl;
        return;
      }
      cout << "출금완료" << endl<<endl;
      return;
    }
  }
  cout << "계좌가 존재하지않습니다." << endl;
}

void User::ShowAccount() const
{
  cout << "계좌ID : " << this->userid << endl;
  cout << "이름 : " << this->uname << endl;
  cout << "잔액 : " << this->ucash << endl;
}

void NormalUser::ShowAccount() const
{
  User::ShowAccount();
  cout<<"이자율 : "<<interest<<endl;
}

void HighCreditUser::ShowAccount() const
{
  NormalUser::ShowAccount();
  if (credit == CREDIT::A)
    cout<<"신용등급 : A  이자율 : "<<credit<<endl;
  else if (credit == CREDIT::B)
    cout<<"신용등급 : B  이자율 : "<<credit<<endl;
  else if (credit == CREDIT::C)
    cout<<"신용등급 : C  이자율 : "<<credit<<endl;
  else
    cout<<"신용등급을 알 수 없습니다."<<endl;
}

void UserHandler::ShowAccount(void) {
  for (int i = 0; i < count; i++) {
    if (user[i]->GetID() != 0) {
      {
        cout<<"-------------계좌 정보-----------------"<<endl;
        user[i]->ShowAccount();
        cout<<"---------------------------------------"<<endl<<endl;
      }
    } else {
      cout << endl << "계좌가 존재하지 않습니다." << endl<<endl;
    }
  }
}

User::~User()
{
  delete []uname;
}

UserHandler::~UserHandler()
{
  for (int i = 0; i < count; i++)
    delete user[i];
}
