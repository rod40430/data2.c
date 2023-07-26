#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS
{
  enum COMP_POS {CLERK , SENIOR, ASSIST, MANGER};
  
  void ShowRank(int rank)
  {
    cout<<"직급 : ";
    if (rank == 0)
      cout<<"사원"<<endl<<endl;
    else if (rank == 1)
      cout<<"주임"<<endl<<endl;
    else if (rank == 2)
      cout<<"대리"<<endl<<endl;
    else if (rank == 3)
      cout<<"과장"<<endl<<endl;
    else
      cout<<"알 수 없는 직책"<<endl<<endl;
  }
}

class NameCard
{
  private:
  int rank;  // 직급
  char * name;  // 이름
  char * company;  // 회사
  char * phonenumber;  // 전화번호

public:
  NameCard(char * n, char * c, char * p, int pos)
  {
    name = new char[strlen(n) + 1];
    name = strcpy(name, n);
    company = new char[strlen(c) + 1];
    company = strcpy(company, c);
    phonenumber = new char[strlen(p) + 1];
    phonenumber = strcpy(phonenumber, p);
    rank = pos;
  }
  void ShowInfo() const
  {
    cout<<"이름 : "<<name<<endl;
    cout<<"회사 : "<<company<<endl;
    cout<<"전화번호 : "<<phonenumber<<endl;
    COMP_POS::ShowRank(rank);
  }
  ~NameCard()
  {
    delete []name;
    delete []company;
    delete []phonenumber;
  }
};

int main(void)
{
  NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
  NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
  NameCard manASSIST("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
  manClerk.ShowInfo();
  manSENIOR.ShowInfo();
  manASSIST.ShowInfo();

  return 0;
}
