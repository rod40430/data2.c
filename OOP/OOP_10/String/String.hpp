#ifndef __STRING_H_
#define __STRING_H_

#include "../BankingCommonDecl.hpp"
class String
{
private:
  int len;
  char * str;
public:
  String();
  String(const char * s);
  String(const String& s);
  ~String();

  String& operator= (const String& s);
  String operator+ (const String& s);
  String& operator+= (const String& s);
  bool operator== (const String& s);

  friend ostream& operator<< (ostream& os, const String& ref);
  friend istream& operator>> (istream& is, String& ref);
};

#endif