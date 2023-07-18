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

typedef struct Car
{
  int fuelGauge;
  int curSpeed;
  char gamerID[ID_LEN];

  void ShowCarState();  // 상태정보 출력
  void Accel();  // 액셀, 속도증가
  void Break();  // 브레이크, 속도감소
} car;

int main(void)
{
  car run99 = 
  {
    100,
    0,
    "run99"
  };

  run99.Accel();
  run99.ShowCarState();
  run99.Break();
  run99.ShowCarState();

  return 0;
}

void car::ShowCarState()
{
  cout<<"소유자ID : "<<gamerID<<endl;
  cout<<"연료량 : "<<fuelGauge<<"%"<<endl;
  cout<<"현재속도 : "<<curSpeed<<"Km/s"<<endl<<endl;
}

void car::Accel()
{
  if (fuelGauge <= 0)
    return;
    
  else
    fuelGauge -= FUEL_STEP;

  if((curSpeed + ACC_STEP) >= MAX_SPD)
  {
    curSpeed = MAX_SPD;
    return;
  }

  curSpeed += ACC_STEP;
}

void car::Break()
{
  if (curSpeed < BRK_STEP)
  {
    curSpeed = 0;
    return;
  }

  curSpeed -= BRK_STEP;
}
