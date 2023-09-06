#include "../BankingCommonDecl.hpp"
#include "Exception.hpp"

MinusException::MinusException(int cash) : money(cash) {}

void MinusException::ShowExceptionInfo(void) const
{
  cout<<"입(출)금액 "<<money<<"는 유효하지 않습니다."<<endl;
}

InsuffException::InsuffException(int ucash, int money) : ucash(ucash), money(money) {}

void InsuffException::ShowExceptionInfo() const
{
  cout<<"현재 잔액 : "<<ucash<<endl;
  cout<<"출금 금액 : "<<money<<endl;
  cout<<"부족한 잔액 : "<<money - ucash<<endl<<endl;
}