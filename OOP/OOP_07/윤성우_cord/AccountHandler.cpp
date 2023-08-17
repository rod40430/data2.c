/*
파일이름 : AccountHandler.cpp
작성자 : 윤성우
업데이트 정보 : 파일버전 0.7
*/

#include "BankingCommonDecl.hpp"
#include "AccountHandler.hpp"
#include "Account.hpp"
#include "NormalAccount.hpp"
#include "HighCreditAccount.hpp"

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowMenu(void) const{
  cout << "-----Menu-----" << endl;
  cout << "1. 계좌개설" << endl;
  cout << "2. 입 금" << endl;
  cout << "3. 출 금" << endl;
  cout << "4. 계좌정보 전체 출력" << endl;
  cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
  int sel;
  cout<<"[계좌종류선택]"<<endl;
  cout<<"1.보통예금계좌";
  cout<<"2.신용신뢰계좌"<<endl;
  cout<<"선택 : ";
  cin>>sel;

  if (sel == NORMAL)
    MakeNormalAccount();
  else
    MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
  int id;
  char name[NAME_LEN];
  int balance;
  int interRate;

  cout << "[계좌계설]" << endl;
  cout << "계좌ID : ";
  cin >> id;
  cout << "이 름 : ";
  cin >> name;
  cout << "입금액 : ";
  cin >> balance;
  cout<<"이자율 : ";
  cin>>interRate;
  cout << endl;

  accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void) {
  int id;
  char name[NAME_LEN];
  int balance;
  int interRate;
  int creditLevel;

  cout << "[계좌계설]" << endl;
  cout << "계좌ID : ";
  cin >> id;
  cout << "이 름 : ";
  cin >> name;
  cout << "입금액 : ";
  cin >> balance;
  cout<<"이자율 : ";
  cin>>interRate;
  cout<<"신용등급(1toA, 2toB, 3toC) : ";
  cin>>creditLevel;
  cout << endl;

  switch (creditLevel)
    {
      case 1:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
        break;
      
      case 2:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
        break;
      
      case 3:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
        break;
    }
}

void AccountHandler::DepositMoney(void) {
  int money;
  int id;
  cout << "[입 금]" << endl;
  cout << "계좌ID : ";
  cin >> id;
  cout << "입금액 : ";
  cin >> money;

  for (int i = 0; i < accNum; i++) {
    if (accArr[i]->GetAccID() == id) {
      accArr[i]->Deposit(money);
      cout << "입금완료" << endl << endl;
      return;
    }
  }
  cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
  int money;
  int id;
  cout << "[출 금]" << endl;
  cout << "계좌ID : ";
  cin >> id;
  cout << "출금액 : ";
  cin >> money;

  for (int i = 0; i < accNum; i++) {
    if (accArr[i]->GetAccID() == id) {
      if (accArr[i]->Withdraw(money) == 0) {
        cout << "잔액부족" << endl << endl;
        return;
      }

      cout << "출금완료" << endl << endl;
      return;
    }
  }
  cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) {
  for (int i = 0; i < accNum; i++) {
    accArr[i]->ShowAccount();
    cout << endl;
  }
}

AccountHandler::~AccountHandler()
{
  for (int i = 0; i < accNum; i++)
    delete accArr[i];
}