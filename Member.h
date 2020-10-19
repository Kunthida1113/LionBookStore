#include<iostream>
#include<string>
//#include "Book.h"
using namespace std;
class Member{
	private:
		string Name;
		string Lastname;		
		string IdMember;
		string password;
		string Type;
		string Status;
		string IdCreditCard;
	public:
		Member();
		Member(string name,string lastname,string idMember,string pass,string type,string status,string idCredit);
		Book SearchNameBook(string nameBook);
		void SetMember(string name,string lastname,string pass);
		Member GetMember(string idMember);
		void SetType(string type);
		bool Pay(string amountofMoney,string idCredit,string idBill);
		void SearchUser(string idUser,string pass);
		Book RentBooks(string idBook);
};
