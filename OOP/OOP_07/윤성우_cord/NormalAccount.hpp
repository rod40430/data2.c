/*
파일이름 : NormalAccount.hpp
작성자 : 윤성우
업데이터 정보 : 파일버전 0.7
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.hpp"

// 클래스 이름 : NormalAccount
// 클래스 유형 : Entity 클래스
class NormalAccount : public Account
{
private:
  int interRate;  // 이자율 %단위
public:
  NormalAccount(int ID, int money, char * name, int rate)
    : Account(ID, money, name), interRate(rate)
  {}

  virtual void Deposit(int money)
  {
    Account::Deposit(money);  // 원급추가
    Account::Deposit(money * (interRate / 100.0));  // 이자추가
  }
};

#endif