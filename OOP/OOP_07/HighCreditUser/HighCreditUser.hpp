#ifndef __HIGHCREDITUSER_H__
#define __HIGHCREDITUSER_H__

#include "../NormalUser/NormalUser.hpp"

class HighCreditUser : public NormalUser
{
private:
  int credit;
public:
  HighCreditUser(int id, int cash, char * name, int inter, int cred);
  void InCash(int money);
  void ShowAccount() const;
};

#endif