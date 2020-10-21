#include"Staff.h"
Staff::Staff(){
    Name = " ";
	Surname = " ";
	Division = " ";
	IdStaff = " ";
	password = " ";
}
void Staff::SetStaff(string id, string pass){
	IdStaff = id;
	password = pass;
}
Staff Staff::getStaff(string idUser){
	
}
string Staff::getId(){
    return IdStaff;
}
string Staff::getPass(){
    return password;
}
void Staff::showRentBookReport(){
	
}
void Staff::showBuyBookReport(){
	
}
void Staff::showPreOrderBookReport(){
	
}
void Staff::AddBook(string idBook,string NameBook,string Author){
	
}
void Staff::SearchUser(string idUser,string password){
	
}
