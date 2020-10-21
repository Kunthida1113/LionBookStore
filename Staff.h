#ifndef STAFF_H
#define STAFF_H
#include<iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Staff{
	private :
		string Name;
		string Surname;
		string Division;
		string IdStaff;
		string password;
	public :
		Staff();
		Staff getStaff(string idUser);
		string getId(); //เพิ่ม
		string getPass(); //เพิ่ม
		void showRentBookReport();
		void showBuyBookReport();
		void showPreOrderBookReport();
		void SetStaff(string idStaff, string password);//เพิ่ม
		void AddBook(string IdBook,string NameBook,string Author,string year,string cate,double RentPrice,double buyPrice,double PrePrice);
		void Login(string idUser,string password);
		void SearchUser(string idUser,string password);
};
#endif