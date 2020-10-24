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
		string Lastname;		
		string Lastname;
		string IdMember;
		string password;
		string Type;
		string Status; //จะมีดีไหม
		string IdCredit;
	public:
		Member();
		Member(string surname,string lastname,string idMember,string pass, string status);
		Book SearchNameBook(string nameBook);
		void SetMember(string name,string lastname,string idMember,string pass, string status);
		Member getMember(string idMember); //เปลี่ยน G เป็น g
		string getId(); //เพิ่ม
		string getPass(); //เพิ่ม
		void readfileMember(); //เพิ่ม
		Member(string surname,string lastname,string idMember,string pass,string type,string status,string idCreditCard);
		Book SearchNameBook(string nameBook);
		Member GetMember(string idMember);
		//Book SearchNameBook(string nameBook);
		void SetMember(string name,string lastname,string idMember,string pass, string status);
		Member getMember(string idMember); //เปลี่ยน G เป็น g
		string getId(); //เพิ่ม
		string getPass(); //เพิ่ม
		string getIdCredit();
		void readfileMember(); //เพิ่ม
		void SetType(string type);
		bool RentPay(DbLinkListed *L,string idCreditCard,string idBill);
		bool BuyPay(DbLinkListed *L,string idCreditCard,string idBill);
		bool PrePay(DbLinkListed *L,string idCreditCard,string idBill);
		void SearchUser(string idUser,string pass);
		Book RentBooks(string idBook);
};
#endif
