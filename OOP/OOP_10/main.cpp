#include "BankingCommonDecl.hpp"
#include "UserHandler/UserHandler.hpp"

int main(void) {
  UserHandler user;
  int choice;

  while (1) {
    user.ShowMenu();
    cin >> choice;
    cout << endl;

    if (choice == CREATE) {
      user.CreateAccount();
    }

    else if (choice == INCASH) {
      user.InCash();
    }

    else if (choice == OUTCASH) {
      user.OutCash();
    }

    else if (choice == SHOWINFO) {
      user.ShowAccount();
    }

    else if (choice == EXIT) {
      cout<<"프로그램을 종료합니다."<<endl;
      return 0;
    }

    else {
      cout << "1~5번 중에 골라주세요.";
    }
  }

  return 0;
}