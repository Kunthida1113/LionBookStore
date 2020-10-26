#ifndef BILL_H
#define BILL_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<string>
#include"Member.h"
#include "DbLinkedList.h"
using namespace std;
class Bill{
	private:
			string IDBill;
	public:
			Bill();
			double getAmountOfMoney();
			void setIDBill();
			void writeFile(string id,double money);
			string runIDBill();
			double Calculate(double money);
			double CalculateRent(DbLinkedList * L);
			double CalculateBuy(DbLinkedList * L);
			double CalculatePre(DbLinkedList * L);
			void ShowRentBill(Member m,DbLinkedList * L);
			void ShowBuyBill(Member m,DbLinkedList * L);
			void ShowPreBill(Member m,DbLinkedList * L);
			void ShowRegisterBill(Member m,double money);
};
#endif
