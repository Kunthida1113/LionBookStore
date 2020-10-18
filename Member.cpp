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
Member::Member(string Name,string Surname,string IdMember,string password,string Type,string Status,string IDCreditCard){
  
}
Book Member::SearchNameBook(string NameBook){

}
void Member::SetMember(string Name,string Surname,string password){

}
Member Member::getMember(string IdMember){
    
}
string Member::getId(){
    return IdMember;
}
string Member::getPass(){
    return password;
}
void Member::SetType(string Type){

}
bool Member::Pay(string amountofMoney,string IDCreditCard,string IDBill){

}
void Member::SearchUser(string IdUser,string password){

}
Book Member::RentBooks(string IdBook){
    
}