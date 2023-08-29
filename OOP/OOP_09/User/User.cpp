#include "../BankingCommonDecl.hpp"
#include "User.hpp"

User::User(int id, int cash, String name)
    :userid(id), ucash(cash)
{
  uname = name;
}

int User::GetID(void) const
{
  return userid;
}

void User::InCash(int money)
{
  ucash += money;
}

int User::OutCash(int money)
{
  if (ucash < money)
    return 0;

  ucash -= money;
  return money;
}

void User::ShowAccount() const
{
  cout << "계좌ID : " << this->userid << endl;
  cout << "이름 : " << this->uname << endl;
  cout << "잔액 : " << this->ucash << endl;
}