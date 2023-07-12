#include "BankingSystemVer01.hpp"
#include <iostream>

using namespace std;

User user[MAX];

int main(void) {
  int choice;
  int count = 0;

  while (1) {
    ShowMenu();
    cin >> choice;
    cout << endl;

    if (choice == 1) {
      CreateAccount(user, count);
      count++;
    }

    else if (choice == 2) {
      InCash(user, count);
    }

    else if (choice == 3) {
      OutCash(user, count);
    }

    else if (choice == 4) {
      ShowAccount(user, count);
    }

    else if (choice == 5) {
      cout << "프로그램을 종료합니다.";
      exit(1);
    }

    else {
      cout << "1~5번 중에 골라주세요.";
    }
  }

  return 0;
}
