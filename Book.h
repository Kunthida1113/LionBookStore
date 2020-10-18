#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
using namespace std;
class Book{
	private:
		string IdBook;
		string NameBook;
		string Author;
		double RentPrice;
		double SellPrice;
		double PrePrice;
	public:
        Book();
        void SetBook(string idBook,string nameBook,string author,double rentPrice,double sellPrice,double prePrice);
		Book SelectCategoryBook();
		Book SearchBook(string nameBook);
		Book RentBook(string idBook);
		Book BuyBook(string idBook);
		Book PreOrderBook(string idBook);    
};
#endif