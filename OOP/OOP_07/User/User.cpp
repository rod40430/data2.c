#include "../BankingCommonDecl.hpp"
#include "User.hpp"

User::User(int id, int cash, char * name)
    :userid(id), ucash(cash)
{
  uname = new char[strlen(name) + 1];
  strcpy(uname, name);
}

User::User(const User &copy)
  : userid(copy.userid), ucash(copy.ucash)
{
  uname = new char[strlen(copy.uname) + 1];
  strcpy(uname, copy.uname);
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

User::~User()
{
  delete []uname;
}
