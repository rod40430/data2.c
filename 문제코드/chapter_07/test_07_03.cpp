#include <iostream>

using namespace std;

class Rectangle
{
private:
  int xnum;  // 가로
  int ynum;  // 세로
public:
  Rectangle(int x, int y) : xnum(x), ynum(y)
  {}
  int Area() {return xnum * ynum;}
  void ShowAreaInfo()
  {
    cout<<"면적 : "<<Area()<<endl;
  }
};

class Square : public Rectangle
{
public:
  Square(int xy) : Rectangle(xy, xy) {}
};

int main(void)
{
  Rectangle rec(4, 3);
  rec.ShowAreaInfo();

  Square sqr(7);
  sqr.ShowAreaInfo();

  return 0;
}
