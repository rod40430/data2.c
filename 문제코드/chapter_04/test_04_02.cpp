#include <iostream>

using namespace std;

class Point
{
private:
  int xpos, ypos;

public:
  void Init(int x, int y)
  {
    xpos = x;
    ypos = y;
  }

  void ShowPointInfo() const
  {
    cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
  }
};

class Circle
{
private:
  Point pin;
  double radius;

public:
  void Init(int x, int y, double rad)
  {
    pin.Init(x, y);
    radius = rad;
  }

  void ShowCircle() const
  {
    cout<<"radius : "<<radius<<endl;
    pin.ShowPointInfo();
  }
};

class Ring
{
private:
  Circle inner;
  Circle outter;

public:
  void Init(int x1, int y1, double rad1, int x2, int y2, double rad2)
  {
    inner.Init(x1, y1, rad1);
    outter.Init(x2, y2, rad2);
  }
  void ShowRing() const
  {
    cout<<"Inner Circle Info..."<<endl;
    inner.ShowCircle();
    cout<<"Outter Circle Info..."<<endl;
    outter.ShowCircle();
  }
};

int main(void)
{
  Ring ring;
  ring.Init(1, 1, 4, 2, 2, 9);
  ring.ShowRing();

  return 0;
}
