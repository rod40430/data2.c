#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

typedef struct Car
{
  int fuelGauge;  // 연료량
  int curSpeed;  //현재 속도
  char gamerID[ID_LEN];  // 소유자 ID

  void ShowCarState()
  {
    cout<<"소유자ID : "<<gamerID<<endl;
    cout<<"연료량 : "<<fuelGauge<<"%"<<endl;
    cout<<"현재속도 : "<<curSpeed<<"km/s"<<endl<<endl;
  }

  void Accel()
  {
    if (fuelGauge <= 0)
      return;
    else
      fuelGauge -= FUEL_STEP;
  
    if (curSpeed + ACC_STEP >= MAX_SPD)
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
    100,  // 연료량
    0,  // 현재속도
    "run99"  // 소유자ID
  };

  run99.Accel();
  run99.Accel();
  run99.ShowCarState();
  run99.Break();
  run99.ShowCarState();

  car sped77 = 
  {
    100,
    0,
    "sped77"
  };

  sped77.Accel();
  sped77.Break();
  sped77.ShowCarState();

  return 0;
}
