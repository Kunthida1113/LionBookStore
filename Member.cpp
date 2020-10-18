#include "Member.h"
Member::Member(){
    Name = " ";    
    Lastname = " ";
    IdMember = " ";
    password = " ";
    Type = " ";
    Status = " ";
    IdCreditCard = " ";
}
Member::Member(string name,string lastname,string idMember,string pass,string type,string status,string idCredit){
       Name = name ;
       Lastname = lastname;
       IdMember = idMember;
       password = pass;
       Type = type ;
       Status = status;
       IdCreditCard  = idCredit;
}
Book Member::SearchNameBook(string NameBook){

}
void Member::SetMember(string name,string lastname,string pass){
           Name = name;
           Lastname = lastname ;
           password = pass;
}
Member Member::GetMember(string IdMember){

}
void Member::SetType(string Type){

}
bool Member::Pay(string amountofMoney,string IDCreditCard,string IDBill){

}
void Member::SearchUser(string IdUser,string password){

}
Book Member::RentBooks(string IdBook){
    
}
