/*
파일이름 : AccountHandler.hpp
작성자 : 윤성우
업데이트 정보 : 파일버전 0.7
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.hpp"

// 클래스 이름 : AccountHandler
// 클래스 유형 : 컨트롤(Control) 클래스
class AccountHandler
{
private:
  Account *accArr[100]; // Account 저장을 위한 배열
  int accNum = 0;
public:
  AccountHandler();

  void ShowMenu(void) const;
  void MakeAccount(void);
  void DepositMoney(void);
  void WithdrawMoney(void);
  void ShowAllAccInfo(void);
  ~AccountHandler();

protected:
  void MakeNormalAccount(void);
  void MakeCreditAccount(void);
};

#endif