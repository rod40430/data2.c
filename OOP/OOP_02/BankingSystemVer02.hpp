#ifndef __BankingSystemVer_H_
#define __BankingSystemVer_H_

// OOP 단게별 프로젝트 02단계

int const USER_COUNT = 20;

namespace Menu
{
  enum Menu
  {
    CREATE_ACCOUNT = 1,
    INCASH, OUTCASH, 
    SHOW_ACCOUNT,
    EIXT
  };
}


class User
{
private:
  int userid;
  int ucash;
  char * uname;
  int count;

public:
  User(int id, int cash, char * name);
  void CreateAccount(void);  // 계좌생성
  void InCash(void);  // 입금
  void OutCash(void);  // 출금
  void ShowAccount(void) const;  //잔액 조회
  ~User();
};
int ShowMenu(void);  //메뉴출력

#endif
