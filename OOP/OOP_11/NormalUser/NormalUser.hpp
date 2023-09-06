#ifndef __NORMALUSER_H__
#define __NORMALUSER_H__

#include "../User/User.hpp"
#include "../String/String.hpp"
#include "../Exception/Exception.hpp"

class NormalUser : public User
{
private:
  int interest;  // 은행 이자율
public:
  NormalUser(int id, int cash, String name, int inter);
  void InCash(int money);
  void ShowAccount() const;
};

#endif