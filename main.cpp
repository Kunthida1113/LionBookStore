#include <iostream>
#include <string>
#include "DbLinkedList.h"
#include "RegisterController.h"
#include "LoginController.h"
#include "BookStoreController.h"
using namespace std;

int main(){
    RegisterController R;
    LoginController L;
    BookStoreController ST;
    DbLinkedList Db;
    int num=0;
    string Name, Lastname, id, pass, status,namebook,IDCreditCard;
    string check;
    int menu,mainMenu,searchMenu, Cstatus;
    bool statusLogin;
    L.readfileMember();
    L.readfileStaff();
    do{
            //intro
            check = " ";
            cout << "========== LionBookStore ==========" << endl;
            cout << " 1.Regiter" << endl;
            cout << " 2.Login" << endl;
            cout << " 3.Exit" << endl;
            cout << "===================================" << endl;
            cin >> menu;
            if(menu==1){
                cout << "======= Regiter ========" << endl;
                cout << "Enter Name: ";
                cin >> Name;
                cout << "Enter Lastname: ";
                cin >> Lastname;
                cout << "Enter Password: ";
                cin >> pass;
                cout << "======= Status =======" << endl;
                cout << " 1.General Member" << endl;
                cout << " 2.VIP Member" << endl;
                cout << "Enter Status:" << endl;
                cin >> Cstatus;
                cout << "Enter ID CreditCard: " ;
                cin >> IDCreditCard;
                if(Cstatus==1){
                    status = "General";
                }else if(Cstatus==2){
                    status = "VIP";
                }
                cout << "Your IdMember: " << R.Register(Name,Lastname,pass,status,IDCreditCard) << endl;
                L.readfileMember();
                do{
                    cout << "======= Login ========" << endl;
                    cout << "Enter IdMember: ";
                    cin >> id;
                    cout << "Enter Password: ";
                    cin >> pass;
                    statusLogin = L.SearchUser(id,pass);
                    num++;
                    if(num==3){
                        cout << "================= Login =================" << endl;
                        cout << " You have entered the wrong code 3 times." << endl;
                        cout << " Do you want to leave.(Y/N)" << endl;
                        cin >> check;
                        if(check=="Y"){
                            statusLogin = true;
                            num = 0;
                        }
                    }else{
                        check = " ";
                    }  
                }while(statusLogin!=true);
            }else if(menu==2){
                do{
                    cout << "======= Login ========" << endl;
                    cout << "Enter Username: ";
                    cin >> id;
                    cout << "Enter Password: ";
                    cin >> pass;
                    statusLogin = L.SearchUser(id,pass);
                    num++;
                    if(num==3){
                        cout << "================= Login =================" << endl;
                        cout << " You have entered the wrong code 3 times." << endl;
                        cout << " Do you want to leave.(Y/N): " ;
                        cin >> check;
                        if(check=="Y"){
                            statusLogin = true;
                            num = 0;
                        }
                    }else{
                        check = " ";
                    }
                    
                }while(statusLogin!=true);
            }else if(menu!=3){
                cout << "Please fill in the correct information!!!!!" << endl;
            }
        if(check!="Y" && menu!=3){
            do{
                mainMenu=0;
                cout << "=====================================" << endl; //main manu
                cout << "                 Menu                " << endl;
                cout << "=====================================" << endl;
                cout << " 1. Search Book" << endl
                    << " 2. Rent Book" << endl
                    << " 3. Buy Book" << endl
                    << " 4. Pre-Order Book" << endl
                    << " 5. Log Out" << endl;
                cout << "=====================================" << endl;
                cout << "Select Menu: " ;
                cin >> mainMenu;
                if(mainMenu==1){
                    //Search Book
                }else if(mainMenu==2){
                    //Rent Book
                }else if(mainMenu==3){
                    //Buy Book
                }else if(mainMenu==4){
                    //Pre-Order Book
                }else if(mainMenu!=5){
                    cout << "Please fill in the correct information!!!!!" << endl;
                }
            }while(mainMenu!=5);
        }
        
    }while(menu!=3);

    Staff s;
    string idBook,name,aut,y,c;
	double rent,buy,pre;
	int numid,numy;
	cout << " -----------------------------------"  <<endl;
	cout << "|       A       DDDDD     DDDDD     |" <<endl;
	cout << "|      A A      D    D    D    D    |" <<endl;
	cout << "|     A   A     D     D   D     D   |" <<endl;
	cout << "|    AAAAAAA    D    D    D    D    |" <<endl;
	cout << "|   A       A   DDDDD     DDDDD     |" <<endl;
	cout << " -----------------------------------"  <<endl;
	ID:cout<< "idBook: ";
	cin >> idBook;
	numid = idBook.length();
	cout << "NameBook: ";
	cin >> name;
	cout << "Author: ";
	cin >> aut;
	YEAR:cout << "year: ";
	cin >> y;
	numy = y.length();
	cout << "cate: ";
	cin >> c;
	cout << "RentPrice: ";
	cin >> rent;
	cout << "buyPrice: ";
	cin >> buy;
	cout <<"PrePrice: ";
	cin >> pre;
	if(numid != 8){
		cout << "You entered incorrect ID.Please enter again." << endl;
		goto ID;
	}
	if(numy != 4){
		cout << "You entered incorrect year.Please enter again." << endl;
		goto YEAR;
	}
	
	s.AddBook(idBook,name,aut,y,c,rent,buy,pre);
    
    
}