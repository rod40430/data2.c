#include <iostream>

using namespace std;

typedef struct Point
{
  int xpos;
  int ypos;

  void MovePos(int x, int y)
  {
    xpos += x;
    ypos += y;
  }

  void AddPoint(const Point &pos)
  {
    xpos += pos.xpos;
    ypos += pos.ypos;
  }

  void ShowPosition()
  {
    cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
  }

} point;

int main(void)
{
  point pos1 = {12, 4};
  point pos2 = {20, 30};

  pos1.MovePos(-7, 10);
  pos1.ShowPosition();

  pos1.AddPoint(pos2);
  pos1.ShowPosition();

  return 0;
}
