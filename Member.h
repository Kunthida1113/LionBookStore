#ifndef MEMBER_H
#define MEMBER_H
#include<iostream>
#include<string>
#include "Book.h"
using namespace std;
class Member{
	private:
		string Surname;
		string Lastname;		
		string IdMember;
		string password;
		string Type;
		string Status;
		string IdCredit;
	public:
		Member();
		Member(string surname,string lastname,string idMember,string pass,string type,string status,string idCreditCard);
		Book SearchNameBook(string nameBook);
		void SetMember(string surname,string lastname,string pass);
		Member GetMember(string idMember);
		void SetType(string type);
		bool Pay(string amountofMoney,string idCreditCard,string idBill);
		void SearchUser(string idUser,string pass);
		Book RentBooks(string idBook);
};
#endif