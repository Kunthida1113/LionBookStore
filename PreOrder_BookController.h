#include<iostream>
#include<string>
#include"Book.h"
#include"Member.h"

class PreOrder_BookController{
	public:
		Book SelectCategoryBook();
		Book SerachBook(string NameBook);
		Book PreOrderBook(string IdBook);
		double Calculate(Member m,Book b);
		bool Pay(string AmountofMoney,string IDCreditCard,string IDBill);
};
