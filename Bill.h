#include <iostream>
#include"DbLinkedList.h"
#include"Book.h"
#include<sstream>
#include <ctime>
#include <time.h>
#include<fstream>

class Bill{
	private:
		string IDBill;
		double amountOfMoney;
	public:
		bill();
		void setBill();
		double Calculate(double money);
		double CalculateRent(DbLinkedList *L);
		double CalculateBuy(DbLinkedList *L);
		double CalculatePre(DbLinkedList *L);
 		void ShowRent_Bill(Member m,DbLinkedList * L);
 		void ShowBuy_Bill(Member m,DbLinkedList * L);
 		void ShowPret_Bill(Member m,DbLinkedList * L);
};

