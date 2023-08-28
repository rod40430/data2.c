#include "../BankingCommonDecl.hpp"
#include "HighCreditUser.hpp"

HighCreditUser::HighCreditUser(int id, int cash, char * name, int inter, int cred)
    : NormalUser(id, cash, name, inter), credit(cred)
  {}

void HighCreditUser::InCash(int money)
{
  NormalUser::InCash(money);
  User::InCash(money * (credit / 100.0));
}

void HighCreditUser::ShowAccount() const
{
  NormalUser::ShowAccount();
  if (credit == CREDIT::A)
    cout<<"신용등급 : A  이자율 : "<<credit<<endl;
  else if (credit == CREDIT::B)
    cout<<"신용등급 : B  이자율 : "<<credit<<endl;
  else if (credit == CREDIT::C)
    cout<<"신용등급 : C  이자율 : "<<credit<<endl;
  else
    cout<<"신용등급을 알 수 없습니다."<<endl;
}