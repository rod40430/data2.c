#include <iostream>
using namespace std;

class BoundCheck2DIntArray
{
private:
  int ** arr;
  int arrlen1;
  int arrlen2;
public:
  BoundCheck2DIntArray(int len1, int len2) : arrlen1(len1), arrlen2(len2)
  {
    arr = new int*[len1];
    for (int i = 0; i < len1; i++)
      arr[i] = new int[len2];
  }
  
  ~BoundCheck2DIntArray()
  {
    for (int i = 0; i < arrlen1; i++)
      delete []*(arr + i);
    delete []arr;
  }
};