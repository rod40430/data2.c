#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private:
  int price;  // 책의 정가
  char * title;  // 책의 제목
  char * isbn;  // 국제교준도서번호
public:
  Book(char * title, char * isbn, int price) : price(price)
  {
    this->title = new char[strlen(title) + 1];
    this->isbn = new char[strlen(isbn) + 1];
    strcpy(this->title, title);
    strcpy(this->isbn, isbn);
  }
  void ShowBookInfo() const
  {
    cout<<"제목 : "<<title<<endl;
    cout<<"ISBN : "<<isbn<<endl;
    cout<<"가격 : "<<price<<endl;
  }
  ~Book()
  {
    delete []title;
    delete []isbn;
  }
};

class EBook : public Book
{
private:
  char * DRMKey;  // 보안관련 키
public:
  EBook(char * title, char * isbn, int price, char * DRMKey)
    : Book(title, isbn, price)
  {
    this->DRMKey = new char[strlen(DRMKey) + 1];
    strcpy(this->DRMKey, DRMKey);
  }
  void ShowEBookInfo() const
  {
    ShowBookInfo();
    cout<<"인증키 : "<<DRMKey<<endl;
  }
  ~EBook()
  {
    delete []DRMKey;
  }
};

int main(void)
{
  Book book("좋은 C++", "555-12345-890-0", 20000);
  book.ShowBookInfo();
  cout<<endl;
  EBook ebook("좋은 C++ ebook", "555-12345-890-1", 20000, "fdx9w0i8kiw");
  ebook.ShowEBookInfo();

  return 0;
}
