#include <iostream>
using namespace std;

class Point
{
private:
  int xpos, ypos;
public:
  Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
  void ShowPosition() const
  {
    cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
  }
};

template <typename T>
void SwapData(T& num1, T& num2)
{
  T temp = num1;
  num1 = num2;
  num2 = temp;
}

template <typename T>
T SumArray(T arr[], int len)
{
  T sum = 0;
  for (int i = 0; i < len; i++)
    sum+= arr[i];
  return sum;
}

int main(void)
{
  Point ptr1(1, 5);
  Point ptr2(7, 8);
  ptr1.ShowPosition();
  ptr2.ShowPosition();
  SwapData(ptr1, ptr2);
  ptr1.ShowPosition();
  ptr2.ShowPosition();

  int len = 10;
  int arr1[len];
  for (int i = 0; i < 10; i++)
    arr1[i] = i;
  cout<<SumArray(arr1, len)<<endl;
  
  double arr2[len];
  for (int i = 0; i < 10; i++)
      arr2[i] = (0.11 + i);
  cout<<SumArray(arr2, len)<<endl;

  return 0;
}
