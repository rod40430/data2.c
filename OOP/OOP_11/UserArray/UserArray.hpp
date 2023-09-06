#ifndef __USERARRAY_H_
#define __USERARRAY_H_

#include "../BankingCommonDecl.hpp"

template <typename T>
class UserArray
{
private:
  T * arr;
  int arrlen;

  UserArray(const UserArray& arr) {}
  UserArray& operator= (const UserArray& arr) {}
public:
  UserArray(int len = 100);
  T& operator[] (int idx);
  T operator[] (int dix) const;
  int GetArrlen() const;
  ~UserArray();
};

template <typename T>
UserArray<T>::UserArray(int len) : arrlen(len)
{
  arr = new T[arrlen];
}

template <typename T>
T& UserArray<T>::operator[] (int idx)
{
  if (idx < 0 || idx >= arrlen)
  {
    cout<<"Array index out of bound exception"<<endl;
    exit(1);
  }
  return arr[idx];
}

template <typename T>
T UserArray<T>::operator[] (int idx) const
{
  if (idx < 0 || idx >= arrlen)
  {
    cout<<"Array index out of bound exception"<<endl;
    exit(1);
  }
  return arr[idx];
}

template <typename T>
int UserArray<T>::GetArrlen() const
{
  return arrlen;
}

template <typename T>
UserArray<T>::~UserArray()
{
  delete []arr;
}

#endif