// OOP 단게별 프로젝트 05단계
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
  int GetID(void) const;
  void InCash(int money);
  int OutCash(int money);
  void ShowAccount(void) const;
  ~User();
};

class UserHandler
{
private:
  User * user[MAX_USER];  // 유저 최대저장수
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
