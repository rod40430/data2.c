/*
파일 이름 : Account.hpp
작성자 : 윤성우
내용 : 파일버전 0.7
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// 클래스 이름 : Account
// 클래스 유형 : Entity 클래스
class Account {
private:
  int accID;     // 계좌번호
  int balance;   // 잔액
  char *cusName; // 고객이름

public:
  Account(int ID, int money, char *name);
  Account(const Account &ref);

  int GetAccID() const;
  virtual void Deposit(int money);
  int Withdraw(int money);
  void ShowAccount() const;
  ~Account();
};

#endif