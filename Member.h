#ifndef MEMBER_H
#define MEMBER_H
#include<iostream>
#include<string>
#include "Book.h"
using namespace std;
class Member{
	private:
		string Name;
		string Surname;
		string IdMember;
		string password;
		string Type;
		string Status;
		string IdCredit;
	public:
		Member();
		Member(string Name,string Surname,string IdMember,string password,string Type,string Status,string IDCreditCard);
		Book SearchNameBook(string NameBook);
		void SetMember(string Name,string Surname,string password);
		Member GetMember(string IdMember);
		void SetType(string Type);
		bool Pay(string amountofMoney,string IDCreditCard,string IDBill);
		void SearchUser(string IdUser,string password);
		Book RentBooks(string IdBook);
};
#endif