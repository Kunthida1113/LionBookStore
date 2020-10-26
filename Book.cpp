#include"Book.h"
Book::Book(){
    IdBook = "";
    NameBook = "";
    Author = "";
    Year = "";
    Category = "";
    RentPrice = 0;
    BuyPrice = 0;
    PrePrice = 0;
}
void Book::SetBook(string idBook,string nameBook,string author,string year,string cate,double rentPrice,double buyPrice,double prePrice){
    IdBook = idBook;
    NameBook = nameBook;
    Author = author;
    Year = year;
    Category = cate;
    RentPrice = rentPrice;
    BuyPrice = buyPrice;
    PrePrice = prePrice;
}
string Book::getIdBook(){
    return IdBook;
}
string Book::getNameBook(){
    return NameBook;
}
string Book::getAuthor(){
    return Author;
}
string Book::getYear(){
    return Year;
}
string Book::getCate(){
    return Category;
}
double Book::getRentPrice(){
    return RentPrice;
}
double Book::getBuyPrice(){
    return BuyPrice;
}
double Book::getPrePrice(){
    return PrePrice;
}
