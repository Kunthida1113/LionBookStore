#include "Member.h"
Member::Member(){
    Surname = " ";    
    Lastname = " ";
    IdMember = " ";
    password = " ";
    Type = " ";
    Status = " ";
    IdCredit = " ";
}
Member::Member(string name,string lastname,string idMember,string pass, string status){
       Surname = name ;
       Lastname = lastname;
       IdMember = idMember;
       password = pass;
       Status = status;
    Surname = "";
    Lastname = "";
    IdMember = "";
    password = "";
    Type = "";
    Status = "";
    IdCredit = "";
}
Member::Member(string surname,string lastname,string idMember,string pass,string type,string status,string idCreditCard){
  
}
Book Member::SearchNameBook(string nameBook){

}
void Member::SetMember(string name,string lastname,string idMember,string pass, string status){
    Surname = name ;
    Lastname = lastname;
    IdMember = idMember;
    password = pass;
    Status = status;
}
Member Member::getMember(string IdMember){
    
}
string Member::getId(){
    return IdMember;
}
string Member::getPass(){
    return password;
}
string Member::getIDCredit(){
   return IdCredit;
}
Member Member::GetMember(string idMember){

}
void Member::SetType(string type){

}

bool Member::RentPay(DbLinkListed *L,string idCreditCard,Member m){
	if(getIDMember() == idCreditCard){
		double total = 0;
		total = Bill::Calculate(L);
	
		Bill::setBill(total);
		Bill::ShowRent_Bill(m,L);	
	}else{
		return false;
	}
}

bool Member::BuyPay(DbLinkListed *L,string idCreditCard,Member m){
	if(getIDMember() == idCreditCard){
		double total = 0;
		total = Bill::Calculate(L);
	
		Bill::setBill(total);
		Bill::ShowBuy_Bill(m,L);	
	}else{
		return false;
	}
}

bool Member::PrePay(DbLinkListed *L,string idCreditCard,Member m){
	if(getIDMember() == idCreditCard){
		double total = 0;
		total = Bill::Calculate(L);
	
		Bill::setBill(total);
		Bill::ShowPre_Bill(m,L);	
	}else{
		return false;
	}
}

void Member::SearchUser(string idUser,string pass){

}
Book Member::RentBooks(string idBook){
    
}
