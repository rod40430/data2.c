// OOP 단게별 프로젝트 01단계
#define MAX 10

typedef struct user
{
  int userid;
  int ucash;
  char uname[20];
}  User;

void CreateAccount(User arr);  // 계좌개설
void ShowMenu();
void InCash(User arr);  // 입금
void OutCash(User arr);  // 출금
void ShowAccount(User ptr);
