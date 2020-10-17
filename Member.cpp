#include "Member.h"
Member::Member(){
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
void Member::SetMember(string surname,string lastname,string pass){
    Surname = surname;
    Lastname = lastname;
    password = pass;
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