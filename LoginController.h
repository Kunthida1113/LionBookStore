#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include <iostream>
#include <string>
#include "DbLinkedList.h"
#include "Member.h"
#include "Staff.h"
using namespace std;

class LoginController
{
    private:
        DbLinkedList *MemberList;
        string password;
        string idMember;
    public:
        LoginController();
        string SearchUser(string id, string pass);
        void readfileMember();
        ~LoginController();
};
#endif