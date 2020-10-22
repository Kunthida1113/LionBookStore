#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"Book.h"
#include"Member.h"
#include"DbLinkedList.h"
#include "BookStoreController.h"

class PreOrder_BookController{
	public:
		Book SelectCategoryBook();
		Book SerachBook(string NameBook);
		void PreOrderBook(string IdBook);
		double Calculate(Member m,Book b);
		bool Pay(string AmountofMoney,string IDCreditCard,string IDBill);
};
