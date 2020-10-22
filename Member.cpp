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
Member Member::GetMember(string idMember){

}
void Member::SetType(string type){

}
bool Member::Pay(string amountofMoney,string idCreditCard,string idBill){

}
void Member::SearchUser(string idUser,string pass){

}
Book Member::RentBooks(string idBook){
    
}
