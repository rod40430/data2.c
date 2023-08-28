#ifndef __UserHandler_H_
#define __UserHandler_H_

#include "../User/User.hpp"
#include "../UserArray/UserArray.hpp"

class UserHandler
{
private:
  UserArray user;  // 유저 최대저장수
  int count;  // User 저장 수
public:
  UserHandler();
  void ShowMenu(void) const;//메뉴출력
  void CreateAccount(void);  // 계좌개설
  void InCash(void);  // 입금
  void OutCash(void);  // 출금
  void ShowAccount(void);  //잔액 조회
  ~UserHandler();
};

#endif