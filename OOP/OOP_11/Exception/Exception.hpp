#ifndef __EXCEPTION_H_
#define __EXCEPTION_H_

class MinusException
{
private:
  int money;
public:
  MinusException(int cash);
  void ShowExceptionInfo(void) const;
};

class InsuffException
{
private:
  int ucash, money;
public:
  InsuffException(int ucash, int money);
  void ShowExceptionInfo(void) const;
};

#endif