#include "../BankingCommonDecl.hpp"
#include "User.hpp"
#include "../Exception/Exception.hpp"

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
  if (money < 0)
    throw MinusException(money);
  
  ucash += money;
}

int User::OutCash(int money)
{
  if (money < 0)
    throw MinusException(money);
  
  if (ucash < money)
    throw InsuffException(ucash, money);

  ucash -= money;
  return money;
}

void User::ShowAccount() const
{
  cout << "계좌ID : " << this->userid << endl;
  cout << "이름 : " << this->uname << endl;
  cout << "잔액 : " << this->ucash << endl;
}