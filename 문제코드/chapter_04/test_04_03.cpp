#include <iostream>

using namespace std;

class Point
{
private:
  int xpos, ypos;

public:
  Point(int x, int y) :xpos(x),ypos(y) {}

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
  Circle(int x, int y, double red) : pin(x,y), radius(red) {}
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
  Ring(int x1, int y1, double red1, int x2, int y2, double red2)
    : inner(x1, y1, red1), outter(x2, y2, red2) {}
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
  Ring ring(1, 1, 4, 2, 2, 9);
  ring.ShowRing();

  return 0;
}
