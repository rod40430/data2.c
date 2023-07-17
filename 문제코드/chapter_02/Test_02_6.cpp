#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
  srand(time(NULL));

  for (int i = 0; i < 5; i++)
    {
      int num = rand();
      cout<<i + 1<<"번째 : "<<num % 100 + 1<<endl;
    }

  return 0;
}

// srand()는 rand()함수의 시드값을 제공한다.
// rand()는 시드값에서 정해진 수를 출력한다.
// time은 현제 시간을 초로 구해서 출력한다.
// srand()에 time()를 써서 rand의 시드값을 프로그램 실행마다 시드값을 변동시켜 랜덤한 값을 출력한다.
// rand()함수의 리턴값은 랜덤이다. 고로 원하는 수까지의 출력은 % (나머지 연산자)를 사용하여 제한할 수 있다.
