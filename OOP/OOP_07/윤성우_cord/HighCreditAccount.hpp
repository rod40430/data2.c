/*
파일이름 : HighCreditAccount.hpp
작성자 : 윤성우
업데이트 정보 : 파일버전 0.7
*/

#ifndef _HIGHCREDIT_ACCOUNT_H__
#define _HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.hpp"

// 클래스 이름 : HighCreditAccount
// 클래스 유형 : Entity 클래스
class HighCreditAccount : public NormalAccount
{
private:
  int specialRate;
public:
  HighCreditAccount(int ID, int money, char * name, int rate, int special)
    : NormalAccount(ID, money, name, rate), specialRate(special)
  {}

  virtual void Deposit(int money)
  {
    NormalAccount::Deposit(money);  // 원금과 이자추가
    Account::Deposit(money * (specialRate / 100.0));  // 특별이자추가
  }
};

#endif