#include <iostream>
#include"DbLinkedList.h"

class Bill{
	private:
		string IDBill;
		double amountOfMoney;
	public:
		bill();
		void setBill();
		double Calculate();
		double CalculateRent(DbLinkedList * L);
		double CalculateBuy(DbLinkedList * L);
		double CalculatePre(DbLinkedList * L);
};

