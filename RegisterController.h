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
#include "Bill.h"
using namespace std;

class RegisterController
{
    private:
        Bill *Bi;
    public:
        Member Register(string name, string lastname, string password, string type,string IDCreditCard);
        string SelectTypeMember(string Type);
        int NumberMember();
        bool Pay(Member m, string idCredit);
};
#endif