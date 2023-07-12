// OOP 단게별 프로젝트 01단계
const int MAX = 10;

typedef struct
{
  int userid;
  int ucash;
  char uname[MAX];
}  User;

void ShowMenu(void);  //메뉴출력
void CreateAccount(User *user, int count);  // 계좌개설
void InCash(User *user, int count);  // 입금
void OutCash(User *user, int count);  // 출금
void ShowAccount(User *user, int count);  //잔액 조회
