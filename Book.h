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
        void SetBook(string IdBook,string NameBook,string Author,double RentPrice,double SellPrice,double PrePrice);
		Book SelectCategoryBook();
		Book SearchBook(string NameBook);
		Book RentBook(string IdBook);
		Book BuyBook(string IdBook);
		Book PreOrderBook(string IdBook);    
};
