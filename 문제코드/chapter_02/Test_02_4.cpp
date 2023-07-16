#include <iostream>

using namespace std;

typedef struct __Point
{
  int xpos;
  int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
  Point *pptr = new Point;
  pptr->xpos = p1.xpos + p2.xpos;
  pptr->ypos = p1.ypos + p2.ypos;
  
  return *pptr;
}

int main(void)
{
  Point *ptr1 = new Point;
  int &p1 = ptr1->xpos;
  int &p2 = ptr1->ypos;

  cout<<"X축 입력 : ";
  cin>>p1;
  cout<<"Y축 입력 : ";
  cin>>p2;

  Point *ptr2 = new Point;
  int &p3 = ptr2->xpos;
  int &p4 = ptr2->ypos;

  cout<<"X축 입력 : ";
  cin>>p3;
  cout<<"Y축 입력 : ";
  cin>>p4;

  Point &pref = PntAdder(*ptr1, *ptr2);

  cout<<"["<<pref.xpos<<", "<<pref.ypos<<"]"<<endl;

  delete ptr1;
  delete ptr2;
  delete &pref;
  
  return 0;
}
