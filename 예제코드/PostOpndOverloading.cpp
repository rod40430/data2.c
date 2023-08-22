#include <iostream>

using namespace std;

class Point
{
private:
  int xpos, ypos;
public:
  Point(int x = 0, int y = 0) : xpos(x), ypos(y)
  {}
  void ShowPosition() const
  {
    cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
  }
  Point& operator++()  // 전위증가
  {
    xpos++;
    ypos++;

    return *this;
  }
  const Point operator++(int)  //후위증가
  {
    const Point retobj(xpos, ypos);  // const Point retobj(*this);
    xpos++;
    ypos++;

    return retobj;
  }
  friend Point& operator--(Point &ref);
  friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref)  // 전위증가
{
  ref.xpos--;
  ref.ypos--;

  return ref;
}

const Point operator--(Point &ref, int)  // 후위감소
{
  const Point retobj(ref);  // const 객체라 한다.
  ref.xpos--;
  ref.ypos--;
  return retobj;
}

int main(void)
{
  Point pos(3, 5);
  Point cpy;

  cpy = pos--;
  cpy.ShowPosition();
  pos.ShowPosition();

  cpy = pos++;
  cpy.ShowPosition();
  pos.ShowPosition();

  (pos++).ShowPosition();
  pos.ShowPosition();
  (++pos).ShowPosition();

  return 0;
}
