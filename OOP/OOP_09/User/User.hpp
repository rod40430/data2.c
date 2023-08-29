#ifndef __USER_H__
#define __USER_H__

#include "../String/String.hpp"

class User
{
private:
  int userid;
  int ucash;
  String uname;
public:
  User(int id, int cash, String name);

  int GetID(void) const;
  virtual void InCash(int money);
  int OutCash(int money);
  virtual void ShowAccount(void) const;
};

#endif