#include "../BankingCommonDecl.hpp"
#include "NormalUser.hpp"

NormalUser::NormalUser(int id, int cash, String name, int inter)
    : User(id, cash, name), interest(inter)
  {}

void NormalUser::InCash(int money)
{
  User::InCash(money);
  User::InCash(money * (interest / 100.0));
}

void NormalUser::ShowAccount() const
{
  User::ShowAccount();
  cout<<"이자율 : "<<interest<<endl;
}
