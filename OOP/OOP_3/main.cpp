#include "BankingSystemVer03.hpp"
#include <iostream>

using namespace std;


int main(void) {
  User * user[MAX_USER];
  int choice;
  int count = 0;

  while (1) {
    ShowMenu();
    cin >> choice;
    cout << endl;

    if (choice == CREATE) {
      CreateAccount(user, count);
      count++;
    }

    else if (choice == INCASH) {
      InCash(*user, count);
    }

    else if (choice == OUTCASH) {
      OutCash(*user, count);
    }

    else if (choice == SHOWINFO) {
      ShowAccount(*user, count);
    }

    else if (choice == EXIT) {
      cout << "프로그램을 종료합니다."<<endl;
      for (int i = 0; i < count; i++)
        delete user[i];
      exit(1);
    }

    else {
      cout << "1~5번 중에 골라주세요.";
    }
  }

  return 0;
}
