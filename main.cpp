#include <iostream>
#include <string>
#include "DbLinkedList.h"
#include "RegiterController.h"
#include "LoginController.h"
#include "BookStoreController.h"
using namespace std;

int main(){
    RegiterController R;
    LoginController L;
    BookStoreController B;
    DbLinkedList *Db;
    
    string Surname, Lastname, id, pass, status,namebook;
    int menu,mainMenu,searchMenu, Cstatus;
    L.readfileMember();
    L.readfileStaff();
    do{
            cout << "========== LionBookStore ==========" << endl;
            cout << " 1.Regiter" << endl;
            cout << " 2.Login" << endl;
            cout << " 3.Exit" << endl;
            cout << "===================================" << endl;
            cin >> menu;
        do{
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
               // L.SearchUser(id,pass);
            }
                if (L.SearchUser(id,pass)==true){
                    cout<<"====================================="<<endl;
                    cout<<"                MENU"<<endl;
                    cout<<"====================================="<<endl;
                    cout<<"1. Search Book"<<endl;
                    cout<<"2. Rent Book"<<endl;
                    cout<<"3. Buy Book"<<endl;
                    cout<<"4. Pre-Order Book"<<endl;
                    cout<<"5. Logout"<<endl;
                    cout<<"====================================="<<endl;
                    cout<<"Select menu: ";
                    cin >> mainMenu;
                    if(mainMenu<5){
                        switch (mainMenu){
                            case 1:{
                                cout<<"============= Search Book ============="<<endl;
                                cout<<"1. Search of a book title"<<endl;
                                cout<<"2. Back to menu"<<endl;
                                cout<<"======================================="<<endl;
                                cout<<"choose menu: ";
                                cin >> searchMenu;
                                if(searchMenu==1){
                                    cout<<"Please enter the title of the book: ";
                                    cin >> namebook;
                                    Db=B.SearchBook(namebook);
                                    cout <<"===================================================================================================================================================================================================================="<<endl;
                                    cout <<setw(15)<<left<<"No."<<setw(20)<<left<<"ID Books"<<setw(30)<<left<<"Books Name"<<setw(15)<<left<<"Author"<<setw(15)<<left<<"Rental price"<<setw(15)<<left<<"Selling price"<<endl;
                                    cout <<"====================================================================================================================================================================================================================="<<endl;
    
                                }
                                break;
                            }
                            default:{
                                break;   
                            }
                        }
                    }
                }
        }while (mainMenu!=5);
    }while(menu!=3);
    
}