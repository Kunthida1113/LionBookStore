#ifndef BOOKSTORECONTROLLER_H
#define BOOKSTORECONTROLLER_H
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"Book.h"
#include"Member.h"
#include"DbLinkedList.h"

class BookStoreController{
	private:
		DbLinkedList *BookList;
		DbLinkedList *RentBookList;
	public:
		BookStoreController();
		~BookStoreController();
		void LoadInfoBook();
		void SelectCategoryBook();
		void RentBook(string IdBook);
/*		Book SearchBook(string NameBook);
		double Calculate(Member m,Book b);
		bool Pay(string AmountofMoney,string IDCreditCard,string IDBill);*/
};
#endif