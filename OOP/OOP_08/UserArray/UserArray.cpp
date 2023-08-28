#include "UserArray.hpp"
#include "../BankingCommonDecl.hpp"

UserArray::UserArray(int len) : arrlen(len)
{
  arr = new USER_PTR[arrlen];
}

USER_PTR& UserArray::operator[] (int idx)
{
  if (idx < 0 || idx >= arrlen)
  {
    cout<<"Array index out of bound exception"<<endl;
    exit(1);
  }
  return arr[idx];
}

USER_PTR& UserArray::operator[] (int idx) const
{
  if (idx < 0 || idx >= arrlen)
  {
    cout<<"Array index out of bound exception"<<endl;
    exit(1);
  }
  return arr[idx];
}

int UserArray::GetArrlen() const
{
  return arrlen;
}

UserArray::~UserArray()
{
  delete []arr;
}