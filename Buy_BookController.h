#include<iostream>
#include<string>
#include<sstream>
#include"Book.h"
#include"Member.h"

class Buy_BookController{
	public:
		Book SelectCategoryBook();
		Book SerachBook(string NameBook);
		Book BuyBook(string IdBook);
		double Calculate(Book b);
		bool Pay(string AmountofMoney,string IDCreditCard,string IDBill);
};
