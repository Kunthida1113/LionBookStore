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
		string Category;
		double RentPrice;
		double SellPrice;
		double PrePrice;
	public:
        Book();
        void SetBook(string idBook,string nameBook,string author,string category,double rentPrice,double sellPrice,double prePrice);
		Book SelectCategoryBook();
		Book SearchBook(string NameBook);
		Book RentBook(string IdBook);
		Book BuyBook(string IdBook);
		Book PreOrderBook(string IdBook);    
};
#endif