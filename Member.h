#ifndef MEMBER_H
#define MEMBER_H
#include<iostream>
#include<string>
#include <fstream>
#include "Book.h"
using namespace std;
class Member{
	private:
		string Name;
		string Lastname;		
		string IdMember;
		string password;
		string Type;
		string Status; 
		string IdCredit;
		string dateOfRegis;
		string dateOfExpire;
	public:
		Member();
		Member(string name,string lastname,string idMember,string pass,string type,string status,string idCreditCard,string dateReg,string dateEx);
		void SetMember(string name,string lastname,string idMember,string pass,string type, string status,string idCreditCard,string dateReg,string dateEx);
		Member getMember(string idMember);
		string getId(); 
		string getName();
		string getPass(); 
		string getCredit(); 
		void readfileMember();
		void SetType(string type);
};
#endif
