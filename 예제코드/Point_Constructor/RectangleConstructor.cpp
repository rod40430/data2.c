#include <iostream>
#include "Point.hpp"
#include "Rectangle.hpp"

using namespace std;

int main(void)
{
  Rectangle rec(1, 1, 5, 5);
  rec.ShowRecInfo();
  
  return 0;
}
