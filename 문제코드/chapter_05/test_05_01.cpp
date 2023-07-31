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
    strcpy(name, n);
    company = new char[strlen(c) + 1];
    strcpy(company, c);
    phonenumber = new char[strlen(p) + 1];
    strcpy(phonenumber, p);
    rank = pos;
  }
  NameCard(const NameCard &copy)
    :rank(copy.rank)
  {
    name = new char[strlen(copy.name) + 1];
    strcpy(name, copy.name);
    company = new char[strlen(copy.company) + 1];
    strcpy(company, copy.company);
    phonenumber = new char[strlen(copy.phonenumber) + 1];
    strcpy(phonenumber, copy.phonenumber);
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
  NameCard copy1 = manClerk;
  NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
  NameCard copy2 = manSENIOR;

  copy1.ShowInfo();
  copy2.ShowInfo();
  

  return 0;
}
