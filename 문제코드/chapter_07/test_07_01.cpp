#include <iostream>

using namespace std;

class Car  // 기본 연료 자동차
{
private:
  int gasolineGauge;
public:
  Car() : gasolineGauge(0)
  {
    cout<<"Car() : "<<gasolineGauge<<endl;
  }
  Car(int n) : gasolineGauge(n)
  {
    cout<<"Car(int n) : "<<gasolineGauge<<endl;
  }
  int GetGasGauge() const
  {
    return gasolineGauge;
  }
};

class HybridCar : public Car  // 하이브리드 자동차
{
private:
  int electricGauge;
public:
  HybridCar() : electricGauge(0)
  {
    cout<<"HybridCar() : "<<electricGauge<<endl;
  }
  HybridCar(int n1) : Car(n1), electricGauge(0)
    {
      cout<<"HybridCar(int n1) : "<<electricGauge<<endl;
    }
  HybridCar(int n1, int n2) : Car(n1), electricGauge(n2)
  {
    cout<<"HybridCar(int n1, int n2) : "<<electricGauge<<endl;
  }
  int GetElecGauge() const
  {
    return electricGauge;
  }
};

class HybridWaterCar : public HybridCar  // 하이브리드 워터카
{
private:
  int waterCauge;
public:
  HybridWaterCar() : waterCauge(0)
  {
    cout<<"HybridWaterCar() : "<<waterCauge<<endl;
  }
  HybridWaterCar(int n1) : HybridCar(n1), waterCauge(0)
    {
      cout<<"HybridWaterCar(int n1) : "<<waterCauge<<endl;
    }
  HybridWaterCar(int n1, int n2) : HybridCar(n1, n2), waterCauge(0)
  {
    cout<<"HybridWaterCar(int n1, int n2) : "<<waterCauge<<endl;
  }
  HybridWaterCar(int n1, int n2, int n3) : HybridCar(n1, n2), waterCauge(n3)
    {
      cout<<"HybridWaterCar(int n1, int n2, int n3) : "<<waterCauge<<endl;
    }
  void ShowCurrentGauge() const
  {
    cout<<"잔여 가솔린 : "<<GetGasGauge()<<endl;
    cout<<"잔여 전기량 : "<<GetElecGauge()<<endl;
    cout<<"잔여 워터량 : "<<waterCauge<<endl<<endl;
  }
};

int main(void)
{
  HybridWaterCar hwc1;
  hwc1.ShowCurrentGauge();

  HybridWaterCar hwc2(100);
  hwc2.ShowCurrentGauge();

  HybridWaterCar hwc3(100, 100);
  hwc3.ShowCurrentGauge();

  HybridWaterCar hwc4(100, 100, 100);
  hwc4.ShowCurrentGauge();

  return 0;
}
