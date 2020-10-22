#include "Staff.h"
Staff::Staff()
{
	Name = " ";
	Surname = " ";
	Division = " ";
	IdStaff = " ";
	password = " ";
}
void Staff::SetStaff(string id, string pass)
{
	IdStaff = id;
	password = pass;
}
Staff Staff::getStaff(string idUser)
{
}
string Staff::getId()
{
	return IdStaff;
}
string Staff::getPass()
{
	return password;
}
void Staff::showRentBookReport()
{
}
void Staff::showBuyBookReport()
{
}
void Staff::showPreOrderBookReport()
{
}
void Staff::AddBook(string IdBook,string NameBook,string Author,string year,string cate,double RentPrice,double buyPrice,double PrePrice){
	ofstream myfile;
	myfile.open("All_Book.txt",ios::app);
	
	string cat,rent,buy,pre;
	
	stringstream r ;
	r << RentPrice; 
	rent = r.str();
	
	stringstream b ;
	b << buyPrice; 
	buy = b.str();
	
	stringstream p ;
	p << PrePrice; 
	pre = p.str();
	
	myfile << IdBook << "," 
	 	   << NameBook << "," 
		   << Author << "," 
		   << year << ","
		   << cate << "," 
		   << rent << "," 
		   << buy << ","
		   << pre << endl;
	myfile.close();		
}
void Staff::SearchUser(string idUser, string password)
{
}
