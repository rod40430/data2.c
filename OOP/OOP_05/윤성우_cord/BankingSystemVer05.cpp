/*
Banking System Ver 0.5
작성자 : 윤성우
내용 : AccountHandler라는 이름의 컨트롤 클래스 정의
*/

#include <cstring>
#include <iostream>

using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// 클래스 이름 : Account
// 클래스 유형 : Entity 클래스
class Account {
private:
  int accID;     // 계좌번호
  int balance;   // 잔액
  char *cusName; // 고객이름

public:
  Account(int ID, int money, char *name);
  Account(const Account &ref);

  int GetAccID() const;
  void Deposit(int money);
  int Withdraw(int money);
  void ShowAccount() const;
  ~Account();
};
Account::Account(int ID, int money, char *name) : accID(ID), balance(money) {
  cusName = new char[strlen(name) + 1];
  strcpy(cusName, name);
}

Account::Account(const Account &ref) : accID(ref.accID), balance(ref.balance) {
  cusName = new char[strlen(ref.cusName) + 1];
  strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) { balance += money; }

int Account::Withdraw(int money) {
  if (balance < money)
    return 0;

  balance -= money;
  return money;
}

void Account::ShowAccount() const {
  cout << "계좌ID : " << accID << endl;
  cout << "이 름 : " << cusName << endl;
  cout << "잔 액 : " << balance << endl;
}

Account::~Account() { delete[] cusName; }

class AccountHandler
{
private:
  Account *accArr[100]; // Account 저장을 위한 배열
  int accNum = 0;
public:
  AccountHandler();

  void ShowMenu(void) const;
  void MakeAccount(void);
  void DepositMoney(void);
  void WithdrawMoney(void);
  void ShowAllAccInfo(void);
  ~AccountHandler();
};

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowMenu(void) const{
  cout << "-----Menu-----" << endl;
  cout << "1. 계좌개설" << endl;
  cout << "2. 입 금" << endl;
  cout << "3. 출 금" << endl;
  cout << "4. 계좌정보 전체 출력" << endl;
  cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void) {
  int id;
  char name[NAME_LEN];
  int balance;

  cout << "[계좌계설]" << endl;
  cout << "계좌ID : ";
  cin >> id;
  cout << "이 름 : ";
  cin >> name;
  cout << "입금액 : ";
  cin >> balance;
  cout << endl;

  accArr[accNum++] = new Account(id, balance, name);
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

// 컨트롤 클래스 AccountHandler 중심으로 변경된 main 함수
int main(void) {
  AccountHandler manger;
  int choice;

  while (1) {
    manger.ShowMenu();
    cout << "선택 : ";
    cin >> choice;
    cout << endl;

    switch (choice) {
    case MAKE:
      manger.MakeAccount();
      break;
    case DEPOSIT:
      manger.DepositMoney();
      break;
    case WITHDRAW:
      manger.WithdrawMoney();
      break;
    case INQUIRE:
      manger.ShowAllAccInfo();
      break;
    case EXIT:
      return 0;

    default:
      cout << "Illegal selection.." << endl;
    }
  }

  return 0;
}
