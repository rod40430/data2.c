#include <iostream>
#include <cstring>
#include "Car.hpp"

using namespace std;
using namespace CAR_CONST;

void car::InitMembers(char *ID, int fuel)
{
  strcpy(gamerID, ID);
  fuelGauge = fuel;
  curSpeed = 0;
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

  if ((curSpeed + ACC_STEP) >= MAX_SPD)
  {
    curSpeed = MAX_SPD;
    return;
  }

  curSpeed += ACC_STEP;
}

void car::Break()
{
  if(curSpeed < BRK_STEP)
  {
    curSpeed = 0;
    return;
  }

  curSpeed -= BRK_STEP;
}
