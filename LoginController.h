#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class LoginController
{
    public:
        LoginController();
        void SearchUser(string id, string pass);
        ~LoginController();
};