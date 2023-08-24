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
  Book(const Book& ref)
    : price(ref.price)
  {
    this->title = new char[strlen(ref.title + 1)];
    this->isbn = new char[strlen(ref.isbn + 1)];
    strcpy(this->title, ref.title);
    strcpy(this->isbn, ref.isbn);
  }
  Book& operator=(const Book& ref)
  {
    delete []title;
    delete []isbn;
    this->title = new char[strlen(ref.title + 1)];
    this->isbn = new char[strlen(ref.isbn + 1)];
    strcpy(this->title, ref.title);
    strcpy(this->isbn, ref.isbn);
    price = ref.price;

    return *this;
  }
  void ShowBookInfo() const
  {
    cout<<"제목 : "<<title<<endl;
    cout<<"ISBN : "<<isbn<<endl;
    cout<<"가격 : "<<price<<endl;
  }
  ~Book()
  {
    cout<<"book 삭제"<<endl;
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
  EBook(const EBook& ref)
    : Book(ref)
  {
    this->DRMKey = new char[strlen(ref.DRMKey) + 1];
    strcpy(this->DRMKey, ref.DRMKey);
  }
  Book& operator=(const EBook& ref)
  {
    Book::operator=(ref);
    delete []DRMKey;
    this->DRMKey = new char[strlen(ref.DRMKey) + 1];
    strcpy(this->DRMKey, ref.DRMKey);

    return *this;
  }
  void ShowEBookInfo() const
  {
    ShowBookInfo();
    cout<<"인증키 : "<<DRMKey<<endl;
  }
  ~EBook()
  {
    cout<<"Ebook 삭제"<<endl;
    delete []DRMKey;
  }
};

int main(void)
{
  Book book1("좋은 C++", "555-12345-890-0", 20000);
  Book book2 = book1;
  book1.ShowBookInfo();
  cout<<endl;
  book2.ShowBookInfo();
  cout<<endl;
  
  
  EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 20000, "fdx9w0i8kiw");
  EBook ebook2 = ebook1;
  ebook1.ShowEBookInfo();
  cout<<endl;
  ebook2.ShowEBookInfo();

  return 0;
}
