#include <iostream>
#include <string>
#include "DbLinkedList.h"
#include "LoginController.h"
using namespace std;

int main(){
    LoginController *L;
    string id, pass, status;
    cout << "======= Login ========" << endl
		<< "Enter Username: ";
	cin >> id;
	cout << "Enter Password: ";
	cin >> pass;
    status = L->SearchUser(id, pass);
    cout << status << endl;
}