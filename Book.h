#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class Book{
	private:
		string IdBook;
		string NameBook;
		string Author;
		string YearOfPub;
		string Category;
		double RentPrice;
		double BuyPrice;
		double PrePrice;
	public:
        Book();
        void SetBook(string idBook,string nameBook,string author,string year,string category,double rentPrice,double buyPrice,double prePrice);
		string getCate();
		string getId();
		string getName();
		string getAuthor();
		string getYear();
		double getRentPrice();
		double getBuyPrice();
		double getPrePrice();
		/*
		Book SelectCategoryBook();
		Book SearchBook(string NameBook);
		Book RentBook(string IdBook);
		Book BuyBook(string IdBook);
		Book PreOrderBook(string IdBook);    */
};
#endif