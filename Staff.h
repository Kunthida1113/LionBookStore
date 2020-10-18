#ifndef STAFF_H
#define STAFF_H
#include<iostream>
#include <string>
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
		void AddBook(string idBook,string NameBook,string Author);
		//void Login(string idUser,string password); //ไม่น่าจะใช้
		void SearchUser(string idUser,string password);
};
#endif