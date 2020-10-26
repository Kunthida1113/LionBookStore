#include "Member.h"
Member::Member(){
    Name = " ";    
    Lastname = " ";
    IdMember = " ";
    password = " ";
    Type = " ";
    Status = " ";
    IdCredit = " ";
    dateOfRegis = " ";
    dateOfExpire = " ";
}
Member::Member(string name,string lastname,string idMember,string pass,string type,string status,string idCreditCard,string dateReg,string dateEx){
    Name = name;    
    Lastname = lastname;
    IdMember = idMember;
    password = pass;
    Type = type;
    Status = status;
    IdCredit = idCreditCard;
    dateOfRegis = dateReg;
    dateOfExpire = dateEx;
}
void Member::SetMember(string name,string lastname,string idMember,string pass,string type, string status,string idCreditCard,string dateReg,string dateEx){
    Name = name ;
    Lastname = lastname;
    IdMember = idMember;
    password = pass;
    Type = type;
    Status = status;
    IdCredit = idCreditCard;
    dateOfRegis = dateReg;
    dateOfExpire = dateEx;    
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
string Member::getCredit(){
    return IdCredit;
}
void Member::SetType(string type){
    Type = type;
}
