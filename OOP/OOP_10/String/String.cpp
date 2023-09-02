#include "./String.hpp"
#include "../BankingCommonDecl.hpp"

String::String()
{
  len = 0;
  str = NULL;
}

String::String(const char * s)
{
  len = strlen(s) + 1;
  str = new char[len];
  strcpy(str, s);
}

String::String(const String& s)
{
  len = s.len;
  str = new char[len];
  strcpy(str, s.str);
}

String::~String()
{
  if (str != NULL)
    delete []str;
}

String& String::operator= (const String& s)
{
  len = s.len;
  if (str != NULL)
    delete []str;

  str = new char[len];
  strcpy(str, s.str);
  return *this;
}

String String::operator+ (const String& s)
{
  char * tempstr = new char[len + s.len - 1];
  strcpy(tempstr, str);
  strcpy(tempstr, s.str);

  String temp(tempstr);
  delete []tempstr;
  return temp;
}

String& String::operator+= (const String& s)
{
  len += (s.len - 1);
  char * tempstr = new char[len];
  strcpy(tempstr, str);
  strcat(tempstr, s.str);

  if (str != NULL)
    delete []str;
  str = tempstr;
  return *this;
}

bool String::operator== (const String& s)
{
  return strcmp(str, s.str) ? false : true;
}

ostream& operator<< (ostream& os, const String& ref)
{
  os<<ref.str;
  return os;
}

istream& operator>> (istream& is, String& ref)
{
  char cpy[100];
  is>>cpy;
  ref = String(cpy);
  return is;
}