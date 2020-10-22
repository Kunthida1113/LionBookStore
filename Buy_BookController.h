#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"Book.h"
#include"Member.h"
#include"DbLinkedList.h"
#include "BookStoreController.h"

class Buy_BookController{
	public:
		Book SelectCategoryBook();
		Book SerachBook(string NameBook);
		void BuyBook(string IdBook);
		double Calculate(Book b);
		bool Pay(string AmountofMoney,string IDCreditCard,string IDBill);
};
