#include <iostream>
#include <string>
#include "DbLinkedList.h"
#include "RegiterController.h"
#include "LoginController.h"
#include"Staff.h"
using namespace std;

int main(){
    RegiterController R;
    LoginController L;
    Member m;
    Staff s;
    string Surname, Lastname, id, pass, status;
    bool checkLogin;
    int menu, Cstatus;
    L.readfileMember();
    L.readfileStaff();
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
            do{
                cout << "======= Login ========" << endl
                    << "Enter Username: ";
                cin >> id;
                cout << "Enter Password: ";
                cin >> pass;
                checkLogin = L.SearchUser(id,pass);
            }while(checkLogin!=true);
            status = id.substr(0, id.find("")+2);
            if(status=="11" || status=="12"){
                m = L.getMember(id);
            }else if(status=="10"){
                s = L.getStaff(id);
            }
        }
    }while(menu!=3);
    Book b;
    string idBook,name,aut,y,c;
	double rent,buy,pre;
	cout<< "idBook: ";
	cin >> idBook;
	cout << "NameBook: ";
	cin >> name;
	cout << "Author: ";
	cin >> aut;
	cout << "year: ";
	cin >> y;
	cout << "cate: ";
	cin >> c;
	cout << "RentPrice: ";
	cin >> rent;
	cout << "buyPrice: ";
	cin >> buy;
	cout <<"PrePrice: ";
	cin >> pre;
	s.AddBook(idBook,name,aut,y,c,rent,buy,pre);
    
}