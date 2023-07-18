#ifndef __CARINLINE_H__  // 만약 __CARINLINE_H__가 정의되어있지않다면. __CARINLINE_H__를 정의해라
#define __CARINLINE_H__

#include <iostream>

namespace CAR_CONST
{
  enum
  {
    ID_LEN = 20,
    MAX_SPD = 200,
    FUEL_STEP = 2,
    ACC_STEP = 10,
    BRK_STEP = 10
  };
}

using namespace CAR_CONST;
using namespace std;

typedef class Car
{
private:
  int fuelGauge;
  int curSpeed;
  char gamerID[ID_LEN];

public:
  void InitMembers(char * ID, int fuel);
  void ShowCarState();
  void Accel();
  void Break();
} car;

inline void car::ShowCarState()
{
  cout<<"소유자ID : "<<gamerID<<endl;
  cout<<"연료량 : "<<fuelGauge<<"%"<<endl;
  cout<<"현재속도 : "<<curSpeed<<"Km/s"<<endl<<endl;
}

inline void car::Break()
{
  if(curSpeed < BRK_STEP)
  {
    curSpeed = 0;
    return;
  }

  curSpeed -= BRK_STEP;
}

#endif
