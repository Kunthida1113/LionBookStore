#ifndef BOOKSTORECONTROLLER_H
#define BOOKSTORECONTROLLER_H
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<ctime>
#include"Book.h"
#include"Member.h"
#include"Staff.h"
#include"Bill.h"
#include"DbLinkedList.h"
using namespace std;
class BookStoreController{
	private:
		DbLinkedList *BookList;
		DbLinkedList *preBookList;
		DbLinkedList *RentBookList;
		DbLinkedList *BuyBookList;
		DbLinkedList *PreBookList;
		Bill *Bi;
	public:
		BookStoreController();
		~BookStoreController();
		void ReadFile(string nameFile);
		void LoadInfoBook();
		void LoadPreBook();
		void AddBook(string idBook,string nameBook,string author,string year,string cate,double rentPrice,double buyPrice,double prePrice);
		void SelectCategoryRentBook(int menuCate);
		void SelectCategoryPreBook(int menuCate);
		void SelectCategoryBuyBook(int menuCate);
		void RentBook(Member m,string IdBook);
		void BuyBook(Member m,string IdBook);
		void PreBook(Member m,string IdBook);
		void ShowBooklist();
		void ShowAllPreBooklist();
		void ShowRentBookList();
		void ShowBuyBookList();
		void ShowPreBookList();
		void SaveRentBookReport();
		void SaveBuyBookReport();
		void SavePreBookReport();
		void SearchBook(string NameBook);
		void SearchPreBook(string NameBook);
		bool PayRentBook(Member m,string IDCredit);
		bool PayBuyBook(Member m,string IDCredit);
		bool PayPreBook(Member m,string IDCredit);
};
#endif