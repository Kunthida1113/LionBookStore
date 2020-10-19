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
		string Year;
		string Category;
		double RentPrice;
		double BuyPrice;
		double PrePrice;
	public:
        Book();
        void SetBook(string IdBook,string NameBook,string Author,string year,string cate,double RentPrice,double buyPrice,double PrePrice);
		string getIdBook();
		string getNameBook();
		string getAuthor();
		string getYear();
		string getCate();
		double getRentPrice();
		double getBuyPrice();
		double getPrePrice();
		Book SelectCategoryBook();
		Book SearchBook(string NameBook);
		Book RentBook(string IdBook);
		Book BuyBook(string IdBook);
		Book PreOrderBook(string IdBook);    
};
#endif