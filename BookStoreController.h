#ifndef BOOKSTORECONTROLLER_H
#define BOOKSTORECONTROLLER_H
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"Book.h"
#include"Member.h"
#include"DbLinkedList.h"
using namespace std;
class BookStoreController{
	private:
		DbLinkedList *BookList;
		DbLinkedList *RentBookList;
	public:
		BookStoreController();
		~BookStoreController();
		void ReadFile(string nameFile);
		void LoadInfoBook();
		void SelectCategoryBook();
		Book RentBook(Member m,string IdBook);
		void ShowRentBookList();
		void SaveReport();
/*		Book SearchBook(string NameBook);
		double Calculate(Member m,Book b);
		bool Pay(string AmountofMoney,string IDCreditCard,string IDBill);*/
};
#endif