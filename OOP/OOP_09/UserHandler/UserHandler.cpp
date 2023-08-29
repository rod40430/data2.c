#include "../BankingCommonDecl.hpp"
#include "UserHandler.hpp"
#include "../NormalUser/NormalUser.hpp"
#include "../HighCreditUser/HighCreditUser.hpp"
#include "../String/String.hpp"

UserHandler::UserHandler() : count(0) {};

void UserHandler::ShowMenu(void) const{
  cout << "-----Menu-----" << endl;
  cout << "1. 계좌개설" << endl;
  cout << "2. 입금" << endl;
  cout << "3. 출금" << endl;
  cout << "4. 계좌정보 전체 출력" << endl;
  cout << "5. 프로그램 종료" << endl;
  cout << "선택 : ";
}

void UserHandler::CreateAccount(void) {
  int choice;
  int id;
  int cash;
  int inter;
  String name;

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

UserHandler::~UserHandler()
{
  for (int i = 0; i < count; i++)
    delete user[i];
}