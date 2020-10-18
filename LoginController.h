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
    public:
        LoginController();
        string SearchUser(string id, string pass);
        ~LoginController();
};
#endif