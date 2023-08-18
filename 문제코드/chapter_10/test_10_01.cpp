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
  friend Point operator+(const Point &pos1, const Point &pos2);
  friend Point operator+=(const Point &pos1, const Point &pos2);
  friend Point operator-=(const Point &pos1, const Point &pos2);
  friend bool operator==(const Point &pos1, const Point &pos2);
  friend bool operator!=(const Point &pos1, const Point &pos2);
};

Point operator+(const Point &pos1, const Point &pos2)
{
  Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
  return pos;
}

Point operator+=(const Point &pos1, const Point &pos2)
{
  Point pos(pos1);
  pos.xpos += pos2.xpos;
  pos.ypos += pos2.ypos;
  return pos;
}

Point operator-=(const Point &pos1, const Point &pos2)
{
  Point pos(pos1);
  pos.xpos -= pos2.xpos;
  pos.ypos -= pos2.ypos;
  return pos;
}

bool operator==(const Point &pos1, const Point &pos2)
{
  if (pos1 == pos2)
    return true;
  else
    return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
  if (pos1 != pos2)
    return false;
  else
    return true;
}

int main(void)
{
  Point pos1(3, 4);
  Point pos2(10, 20);
  Point pos3 = pos1 + pos2;
  Point pos4 = pos1 += pos2;
  Point pos5 = pos1 -= pos2;
  Point pos6 = pos1 == pos2;
  Point pos7 = pos1 != pos2;

  pos1.ShowPosition();
  pos2.ShowPosition();
  pos3.ShowPosition();
  pos4.ShowPosition();
  pos5.ShowPosition();
  pos6.ShowPosition();
  pos7.ShowPosition();

  return 0;
}
