#include "Member.h"
Member::Member(){
<<<<<<< HEAD
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
=======
    Surname = "";
    Lastname = "";
    IdMember = "";
    password = "";
    Type = "";
    Status = "";
    IdCredit = "";
}
Member::Member(string surname,string lastname,string idMember,string pass,string type,string status,string idCreditCard){
  
>>>>>>> 5aec69f3fd36820d66ab13cd1ac1b5e2c4f6d8cf
}
Book Member::SearchNameBook(string nameBook){

}
<<<<<<< HEAD
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
=======
void Member::SetMember(string surname,string lastname,string pass){
    Surname = surname;
    Lastname = lastname;
    password = pass;
}
Member Member::GetMember(string idMember){

>>>>>>> 5aec69f3fd36820d66ab13cd1ac1b5e2c4f6d8cf
}
void Member::SetType(string type){

}
bool Member::Pay(string amountofMoney,string idCreditCard,string idBill){

}
void Member::SearchUser(string idUser,string pass){

}
Book Member::RentBooks(string idBook){
    
}
