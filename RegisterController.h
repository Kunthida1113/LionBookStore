#ifndef REGITERCONTROLLER_H
#define REGITERCONTROLLER_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "DbLinkedList.h"
#include "Member.h"
#include "Staff.h"
using namespace std;

class RegisterController
{
    public:
        string Register(string name, string lastname, string password, string status,string IDCreditCard);
        string SelectTypeMember(string Type);
        int NumberMember();
        bool Pay(string amount, string idCredit, string idBill);
};
#endif