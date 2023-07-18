#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

typedef struct
{
  int fuelGauge;  // 연료량
  int curSpeed;  //현재 속도
  char gamerID[ID_LEN];  // 소유자 ID
} Car;

void ShowCarState(const Car &car)
{
  cout<<"소유자ID : "<<car.gamerID<<endl;
  cout<<"연료량 : "<<car.fuelGauge<<"%"<<endl;
  cout<<"현재속도 : "<<car.curSpeed<<"km/s"<<endl<<endl;
}

void Accel(Car &car)
{
  if (car.fuelGauge <= 0)
    return;
  else
    car.fuelGauge -= FUEL_STEP;

  if (car.curSpeed + ACC_STEP >= MAX_SPD)
  {
    car.curSpeed = MAX_SPD;
    return;
  }

  car.curSpeed += ACC_STEP;
}

void Break(Car &car)
{
  if (car.curSpeed < BRK_STEP)
  {
    car.curSpeed = 0;
    return;
  }

  car.curSpeed -= BRK_STEP;
}

int main(void)
{
  Car run99 = 
  {
    100,  // 연료량
    0,  // 현재속도
    "run99"  // 소유자ID
  };

  Accel(run99);
  Accel(run99);
  ShowCarState(run99);
  Break(run99);
  ShowCarState(run99);

  Car sped77 = 
  {
    100,
    0,
    "sped77"
  };

  Accel(sped77);
  Break(sped77);
  ShowCarState(sped77);

  return 0;
}
