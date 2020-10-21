#ifndef MEMBER_H
#define MEMBER_H
#include<iostream>
#include<string>
#include <fstream>
#include "Book.h"
using namespace std;
class Member{
	private:
		string Surname;
<<<<<<< HEAD
		string Lastname;		
=======
		string Lastname;
>>>>>>> 5aec69f3fd36820d66ab13cd1ac1b5e2c4f6d8cf
		string IdMember;
		string password;
		string Type;
		string Status; //จะมีดีไหม
		string IdCredit;
	public:
		Member();
<<<<<<< HEAD
		Member(string surname,string lastname,string idMember,string pass, string status);
		Book SearchNameBook(string nameBook);
		void SetMember(string name,string lastname,string idMember,string pass, string status);
		Member getMember(string idMember); //เปลี่ยน G เป็น g
		string getId(); //เพิ่ม
		string getPass(); //เพิ่ม
		void readfileMember(); //เพิ่ม
=======
		Member(string surname,string lastname,string idMember,string pass,string type,string status,string idCreditCard);
		Book SearchNameBook(string nameBook);
		void SetMember(string surname,string lastname,string password);
		Member GetMember(string idMember);
>>>>>>> 5aec69f3fd36820d66ab13cd1ac1b5e2c4f6d8cf
		void SetType(string type);
		bool Pay(string amountofMoney,string idCreditCard,string idBill);
		void SearchUser(string idUser,string pass);
		Book RentBooks(string idBook);
};
#endif