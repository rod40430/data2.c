#include "BankingSystemVer01.hpp"
#include <iostream>

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

void CreateAccount(User *user, int i) {
  cout << "[계좌개설]" << endl;
  cout << "계좌ID : ";
  cin >> user[i].userid;
  cout << "이름 : ";
  cin >> user[i].uname;
  cout << "입금액 : ";
  cin >> user[i].ucash;
  cout << endl;
}

void InCash(User *user, int count) {
  int id;
  int money;

  cout << "[입 금]" << endl;
  cout << "계좌ID : ";
  cin >> id;

  for (int i = 0; i < count; i++) {
    if (id == user[i].userid) {
        cout << "입금액 : ";
        cin >> money;
      
      user[i].ucash += money;
      cout << "입금완료" << endl;
    } else {
      cout << "계좌가 존재하지않습니다." << endl;
    }
  }
}

void OutCash(User *user, int count) {
  int id;
  int money;

  cout << "[출 금]" << endl;
  cout << "계좌ID : ";
  cin >> id;

  for (int i = 0; i < count; i++) {
    if (id == user[i].userid) { 
      cout << "출금액 : ";
      cin >> money;
      
      user[i].ucash -= money;
      cout << "출금완료" << endl;
    } else {
      cout << "계좌가 존재하지않습니다." << endl;
    }
  }
}

void ShowAccount(User *user, int count) {
  for (int i = 0; i < count; i++) {
    if (user[i].userid != 0) {
      cout << "계좌ID : " << user[i].userid << endl;
      cout << "이름 : " << user[i].uname << endl;
      cout << "잔액 : " << user[i].ucash << endl;
    } else {
      cout << endl << "더 이상 계좌가 존재하지 않습니다." << endl;
    }
  }
}
