#ifndef __NORMALUSER_H__
#define __NORMALUSER_H__

#include "../User/User.hpp"

class NormalUser : public User
{
private:
  int interest;  // 은행 이자율
public:
  NormalUser(int id, int cash, char * name, int inter);
  void InCash(int money);
  void ShowAccount() const;
};

#endif