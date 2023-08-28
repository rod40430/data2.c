#ifndef __USER_H__
#define __USER_H__

class User
{
private:
  int userid;
  int ucash;
  char * uname;
public:
  User(int id, int cash, char * name);
  User(const User &copy);
  User& operator= (const User& ref);

  int GetID(void) const;
  virtual void InCash(int money);
  int OutCash(int money);
  virtual void ShowAccount(void) const;
  ~User();
};

#endif