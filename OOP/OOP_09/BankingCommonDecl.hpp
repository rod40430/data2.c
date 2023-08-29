#ifndef __BANKINGCOMMONDECL_H_
#define __BANKINGCOMMONDECL_H_

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_USER = 100;

enum {CREATE = 1, INCASH, OUTCASH, SHOWINFO, EXIT};

namespace CREDIT
{
  enum {A = 7, B = 4, C = 2};
}

#endif