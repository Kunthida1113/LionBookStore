#include"Book.h"
Book::Book(){
    IdBook = "";
    NameBook = "";
    Author = "";
    RentPrice = 0;
    SellPrice = 0;
    PrePrice = 0;
}
void Book::SetBook(string idBook,string nameBook,string author,double rentPrice,double sellPrice,double prePrice){
    IdBook = idBook;
    NameBook = nameBook;
    Author = author;
    RentPrice = rentPrice;
    SellPrice = sellPrice;
    PrePrice = prePrice;
}
Book Book::SelectCategoryBook(){

}
Book Book::SearchBook(string NameBook){

}
Book Book::RentBook(string IdBook){

}
Book Book::BuyBook(string IdBook){

}
Book Book::PreOrderBook(string IdBook){

}  