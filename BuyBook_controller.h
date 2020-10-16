#include<iostream>
#include<string>
#include"Book.h"
#include"Member.h"

class Buy_BookController{
	public:
		Book SelectCategoryBook();
		Book SerachBook(string NameBook);
		Book BuyBook(string IdBook);
		double Calculate(Member m,Book b);
		bool Pay(string AmountofMoney,string IDCreditCard,string IDBill);
};
