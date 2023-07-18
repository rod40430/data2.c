#include <iostream>

using namespace std;

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

typedef struct Car
{
  int fuelGauge;
  int curSpeed;
  char gamerID[ID_LEN];

void ShowCarStage()
{
  cout<<"소유자ID : "<<gamerID<<endl;
  cout<<"연료량 : "<<fuelGauge<<"%"<<endl;
  cout<<"현재속도 : "<<curSpeed<<"Km/s"<<endl<<endl;
}

void Accel()
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

void Break()
{
  if (curSpeed < BRK_STEP)
  {
    curSpeed = 0;
    return;
  }

  curSpeed -= BRK_STEP;
}

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
  run99.Accel();
  run99.ShowCarStage();
  run99.Break();
  run99.ShowCarStage();

  car sped77 =
  {
    100,
    0,
    "sped77"
  };

  sped77.Accel();
  sped77.Break();
  sped77.ShowCarStage();

  return 0;
}
