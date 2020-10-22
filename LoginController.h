#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include <iostream>
#include <string>
#include <fstream>
#include "DbLinkedList.h"
#include "Member.h"
#include "Staff.h"
using namespace std;

class LoginController
{
    private:
        DbLinkedList *MemberList;//เพิ่ม
        DbLinkedList *StaffList;//เพิ่ม
    public:
        LoginController();
        bool SearchUser(string id, string pass);
        Member getMember(string id);//เพิ่ม
        Staff getStaff(string id);//เพิ่ม
        void readfileMember();//เพิ่ม
        void readfileStaff(); //เพิ่ม
        ~LoginController();
};
#endif