#include "Member.h"
Member::Member(){
    Name = " ";    
    Lastname = " ";
    IdMember = " ";
    password = " ";
    Type = " ";
    Status = " ";
    IdCredit = " ";
}
Member::Member(string name,string lastname,string idMember,string pass, string status){
       Name= name ;
       Lastname = lastname;
       IdMember = idMember;
       password = pass;
       Status = status;
}
Book Member::SearchNameBook(string NameBook){

}
void Member::SetMember(string name,string lastname,string idMember,string pass, string status){
    Name = name ;
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
string Member::getName(){
    return Name;
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

