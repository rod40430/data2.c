// OOP 단게별 프로젝트 03단계
#ifndef __BankingSystemVer_H_
#define __BankingSystemVer_H_

const int MAX_USER = 100;
const int MAX_STR = 20;

enum {CREATE = 1, INCASH, OUTCASH, SHOWINFO, EXIT};

class User
{
private:
  int userid;
  int ucash;
  char * uname;

public:
  User(int id, int cash, char * name);
  User(const User &copy);
  int GetID(void);
  void InCash(int money);
  int OutCash(int money);
  void ShowAccount(void);
  ~User();
};

void ShowMenu(void);  //메뉴출력
void CreateAccount(User **user, int count);  // 계좌개설
void InCash(User *user, int count);  // 입금
void OutCash(User *user, int count);  // 출금
void ShowAccount(User *user, int count);  //잔액 조회

#endif
