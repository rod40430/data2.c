/*
소프트웨어 버전 : Banking System Ver 0.7

파일이름 : BankingSystemMain.cpp
작성자 : 윤성우
업데이트 정보 : 파일버전 0.7
*/

#include "BankingCommonDecl.hpp"
#include "AccountHandler.hpp"

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