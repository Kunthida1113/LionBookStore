#ifndef STAFF_H
#define STAFF_H
#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include"Book.h"
#include"RentBookReport.h"
#include"BuyBookReport.h"
#include"PreOrderBookReport.h"
using namespace std;

class Staff{
	private :
		string Name;
		string Surname;
		string Division;
		string IdStaff;
		string password;
		RentBookReport R;
		BuyBookReport B;
		PreOrderBookReport P;
	public :
		string getId();
		string getPass();
		Staff getStaff(string idUser);
		void SetStaff(string idStaff, string password);//เพิ่ม
		void showRentBookReport(int m);
		void showBuyBookReport(int m);
		void showPreOrderBookReport(int m);
};
#endif
