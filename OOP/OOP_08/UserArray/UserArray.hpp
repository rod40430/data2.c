#ifndef __USERARRAY_H_
#define __USERARRAY_H_

#include "../User/User.hpp"
typedef User * USER_PTR;

class UserArray
{
private:
  USER_PTR * arr;
  int arrlen;

  UserArray(const UserArray& arr) {}
  UserArray& operator= (const UserArray& arr) {}
public:
  UserArray(int len = 100);
  USER_PTR& operator[] (int idx);
  USER_PTR& operator[] (int dix) const;
  int GetArrlen() const;
  ~UserArray();
};

#endif