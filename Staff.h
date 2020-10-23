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
		Staff getStaff(string idUser);
		void showRentBookReport();
		void showBuyBookReport();
		void showPreOrderBookReport();
		void AddBook(string IdBook,string NameBook,string Author,string year,string cate,double RentPrice,double buyPrice,double PrePrice);
		void Login(string idUser,string password);
		void SearchUser(string idUser,string password);
};
