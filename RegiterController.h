#ifndef REGITERCONTROLLER_H
#define REGITERCONTROLLER_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "DbLinkedList.h"
#include "Member.h"
#include "Staff.h"
using namespace std;

class RegiterController
{
    public:
        void Register(string surname, string lastname, string password, string status);
        void SelectTypeMember(string Type);
        int NumberMember();
        bool Pay(string amount, string idCredit, string idBill);
};
#endif