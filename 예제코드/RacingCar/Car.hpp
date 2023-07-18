#ifndef __CAR_H__  // 만약 CAR_H가 정의되어있지않다면. CAR_H를 정의해라
#define __CAR_H__

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

#endif
