#include <iostream>
#include <string>
#include "DbLinkedList.h"
#include "RegiterController.h"
#include "LoginController.h"
using namespace std;

int main(){
    RegiterController R;
    LoginController L;
    string Surname, Lastname, id, pass, status;
    int menu, Cstatus;
    L.readfileMember();
    do{
        cout << "========== LionBookStore ==========" << endl;
        cout << " 1.Regiter" << endl;
        cout << " 2.Login" << endl;
        cout << " 3.Exit" << endl;
        cout << "===================================" << endl;
        cin >> menu;
        if(menu==1){
            cout << "======= Regiter ========" << endl;
            cout << "Enter Name: ";
            cin >> Surname;
            cout << "Enter Lastname: ";
            cin >> Lastname;
            cout << "Enter Password: ";
            cin >> pass;
            cout << "======= Status =======" << endl;
            cout << " 1.General Member" << endl;
            cout << " 2.VIP Member" << endl;
            cout << "Enter Status:" << endl;
            cin >> Cstatus;
            if(Cstatus==1){
                status = "General";
            }else if(Cstatus==2){
                status = "VIP";
            }
            R.Register(Surname,Lastname,pass,status);
            
        }else if(menu==2){
            cout << "======= Login ========" << endl
                << "Enter Username: ";
            cin >> id;
            cout << "Enter Password: ";
            cin >> pass;
            status = L.SearchUser(id,pass);
            cout << status << endl;
        }
    }while(menu!=3);
    
}