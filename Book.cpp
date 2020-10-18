#include"Book.h"
Book::Book(){
    IdBook = "";
    NameBook = "";
    Author = "";
    YearOfPub = "";
    Category = "";
    RentPrice = 0;
    BuyPrice = 0;
    PrePrice = 0;
}
void Book::SetBook(string idBook,string nameBook,string author,string year,string category,double rentPrice,double buyPrice,double prePrice){
    IdBook = idBook;
    NameBook = nameBook;
    Author = author;
    YearOfPub = year;
    Category = category;
    RentPrice = rentPrice;
    BuyPrice = buyPrice;
    PrePrice = prePrice;
}
string Book::getCate(){
    return Category;
}
string Book::getId(){
    return IdBook;
}
string Book::getName(){
    return NameBook;
}
string Book::getAuthor(){
    return Author;
}
string Book::getYear(){
    return YearOfPub;
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
/*
Book Book::SelectCategoryBook(){

}
Book Book::SearchBook(string NameBook){

}
Book Book::RentBook(string IdBook){

}
Book Book::BuyBook(string IdBook){

}
Book Book::PreOrderBook(string IdBook){

}  */