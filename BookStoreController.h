#ifndef BOOKSTORECONTROLLER_H
#define BOOKSTORECONTROLLER_H
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include"Book.h"
#include"Member.h"
#include"DbLinkedList.h"
using namespace std;
class BookStoreController{
	private:
		DbLinkedList *BookList;
		DbLinkedList *RentBookList;
		DbLinkedList *BuyBookList;
		DbLinkedList *PreBookList;
	public:
		BookStoreController();
		~BookStoreController();
		void ReadFile(string nameFile);
		void LoadInfoBook();
		void SelectCategoryBook();
		void RentBook(Member m,string IdBook);
		void BuyBook(Member m,string IdBook);
		void PreBook(Member m,string IdBook);
		void ShowRentBookList();
		void ShowBuyBookList();
		void ShowPreBookList();
		void SaveRentBookReport();
		void SaveBuyBookReport();
		void SavePreBookReport();
		void SearchBook(string NameBook);
		void LoadPreBook();
//		double CalculateBook(Book b);
//		bool Pay(string AmountofMoney,string IDCreditCard,string IDBill);
};
#endif
