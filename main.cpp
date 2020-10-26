#include <iostream>
#include <string>
#include "Member.h"
#include "Staff.h"
#include "Bill.h"
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
    Member M;
    Staff S;
    int num=0;
    string Name, Lastname, id, pass,type,status,IDCreditCard;
    string namebook="",idBook="",tempCredit="",Credit="";
    string check,idCheck,ans;
    int menu,mainMenu,Cstatus;
    bool statusLogin,statusPay;
    ST.LoadInfoBook();
        int menuCate=0;
    //ST.LoadPreBook();
    //ST.ShowAllPreBooklist();
    do{
        statusLogin = false;
        num=0;
        check="";
            //intro
            ST.ReadFile("IntroLion.txt");
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
                cout << "======= Type Member =======" << endl;
                cout << " 1.General Member" << endl;
                cout << " 2.VIP Member" << endl;
                cout << "==========================="<<endl;
                cout << "Enter Type Member: ";
                cin >> Cstatus;
                cout << "Enter ID CreditCard: ";
                cin >> IDCreditCard;
                if(Cstatus==1){
                    type = "General";
                }else if(Cstatus==2){
                    type = "VIP";
                }
                M = R.Register(Name,Lastname,pass,type,IDCreditCard);
                if(type == "VIP"){
                    do{
                        cout << " --------------------------------------------------------- " <<endl;
                        cout << " =================Pay your VIP register=================== " <<endl;
                        cout << "Enter ID CreditCard : " ;
                         cin >> tempCredit;
                         statusPay = R.Pay(M,tempCredit); 
                         if(statusPay==true){

                            cout << " --------------------------------------------------------- " <<endl;
                             cout<<"\t\t\t\t\tSuccess!!!"<<endl;
                            cout << " --------------------------------------------------------- " <<endl;
                        }
                    }while(statusPay!=true);
                }
                cout << "Your IdMember: " << M.getId() << endl;
                L.readfileMember();
                do{
                    cout << "======= Login ========" << endl;
                    cout << "Enter IdMember: ";
                    cin >> id;
                    cout << "Enter Password: ";
                    cin >> pass;
                    statusLogin = L.SearchUser(id,pass);
                    if(statusLogin!=true&&num==3){
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
                    num++;  
                }while(statusLogin != true && check != "Y"); 
            }else if(menu==2){
                L.readfileStaff();
                L.readfileMember();
                do{
                    cout << "======= Login ========" << endl;
                    cout << "Enter Username: ";
                    cin >> id;
                    cout << "Enter Password: ";
                    cin >> pass;
                    statusLogin = L.SearchUser(id,pass);
                    num++;
                    if(statusLogin!=true&&num==3){
                        cout << "================= Login =================" << endl;
                        cout << " You have entered the wrong code 3 times." << endl;
                        cout << " Do you want to leave.(Y/N): " ;
                        cin >> check;
                        if(check=="N"){
                            cout<<"Please try again!!"<<endl;
                            num = 0;
                            check = "";
                        }
                    }
                }while(statusLogin != true && check != "Y");
            }else if(menu!=3){
                cout << "Please fill in the correct information!!!!!" << endl;
            }
        if(statusLogin == true || menu != 3){
            idCheck = id.substr(0, id.find("")+2);
            if(idCheck=="11"){
                M = L.getMember(id);
                check = " ";
                ans = " ";
                cout<<"M: "<<M.getCredit()<<endl;
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
                        cout<<"Enter Name Book: ";
                        cin.ignore();
                        getline(cin,namebook);
                        ST.SearchBook(namebook);
                    }else if(mainMenu==2){
                        int selRent=0;
                        string again="";
                        do{
                            //Rent Book
                            again="";
                            cout<<"======================================"<<endl;
                            cout<<"              Rent Book"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"1. Select Category Book"<<endl;
                            cout<<"2. Search Book"<<endl;
                            cout<<"3. Back to main menu"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"Select choices: ";
                            cin>>selRent;
                            if(selRent == 1){
                                do{
                                    ST.ReadFile("MenuCate.txt");
                                    cout<<"Select Menu(1-11): ";
                                    cin>>menuCate;
                                    cout<<endl;
                                    if(menuCate > 0 && menuCate < 11){
                                        //show category
                                        ST.SelectCategoryRentBook(menuCate);
                                        cout<<"Do you want to rent book now? (Y/N): ";
                                        cin>>ans;
                                        if(ans=="Y"){
                                            check = "in";
                                        }
                                    }
                                    else{
                                        ans = "Y";
                                        check = "out";
                                    }
                                }while(ans!="Y");
                            }else if(selRent==2){
                                do{
                                    cout<<"Enter Name Book: ";
                                    cin.ignore();
                                    getline(cin,namebook);
                                    ST.SearchBook(namebook);
                                    cout<<"Do you want to rent book now? (Y/N): ";
                                    cin>>ans;
                                }while(ans!="Y");

                            }
                            if(ans == "Y" && check != "out"){
                                cout<<"Enter id book:";
                                cin>>idBook;
                                ST.RentBook(M,idBook);
                                cout<<"Do you want to rent more books? (Y/N) :"; //Y back to rent book 
                                cin>>again;
                                if(again=="N"){
                                    do{
                                        cout << " --------------------------------------------------------- " <<endl;
                                        cout << " =================Pay Rent Book=================== " <<endl;
                                        cout << "Enter ID CreditCard : " ;
                                        cin >> Credit;
                                        statusPay = ST.PayRentBook(M,Credit);
                                        if(statusPay==true){
                                            cout << " --------------------------------------------------------- " <<endl;
                                            cout<<"\t\t\t\t\tSuccess!!!"<<endl;
                                            cout << " --------------------------------------------------------- " <<endl;
                                            ST.SaveRentBookReport();
                                        }
                                    }while(statusPay!=true);                                    
                                    selRent = 3;
                                }
                            }
                            //selRent == 3 back main menu
                        }while(selRent != 3);
                    }else if(mainMenu==3){
                        //Buy Book
                        int selBuy=0;
                        string again;
                        do{
                            again="";
                            cout<<"======================================"<<endl;
                            cout<<"                Buy Book"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"1. Select Category Book"<<endl;
                            cout<<"2. Search Book"<<endl;
                            cout<<"3. Back to main menu"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"Select choices: ";
                            cin>>selBuy;
                            if(selBuy == 1){
                                //show category
                                do{
                                    ST.ReadFile("MenuCate.txt");
                                    cout<<"Select Menu(1-11): ";
                                    cin>>menuCate;
                                    cout<<endl;
                                    if(menuCate > 0 && menuCate < 11){
                                        //show category
                                        ST.SelectCategoryBuyBook(menuCate);
                                        cout<<"Do you want to buy book now? (Y/N): ";
                                        cin>>ans;
                                        if(ans=="Y"){
                                            check = "in";
                                        }
                                    }
                                    else{
                                        ans = "Y";
                                        check = "out";
                                    }
                                }while(ans!="Y");
                            }else if(selBuy==2){
                                //search
                                do{
                                    cout<<"Enter Name Book: ";
                                    cin.ignore();
                                    getline(cin,namebook);
                                    ST.SearchBook(namebook);
                                    cout<<"Do you want to buy book now? (Y/N): ";
                                    cin>>ans;
                                }while(ans!="Y");
                            }
                            if(ans == "Y" && check != "out"){
                                cout<<"Enter id book:";
                                cin>>idBook;
                                ST.BuyBook(M,idBook);
                                cout<<"Do you want to buy more books? (Y/N) :"; //Y back to rent book 
                                cin>>again;
                                if(again=="N"){
                                    do{
                                        cout << " --------------------------------------------------------- " <<endl;
                                        cout << " =================Pay Buy Book=================== " <<endl;
                                        cout << "Enter ID CreditCard : " ;
                                        cin >> Credit;
                                        statusPay = ST.PayBuyBook(M,Credit);
                                        if(statusPay==true){
                                            cout << " --------------------------------------------------------- " <<endl;
                                            cout<<"\t\t\t\t\tSuccess!!!"<<endl;
                                            cout << " --------------------------------------------------------- " <<endl;
                                            ST.SaveBuyBookReport();
                                        }
                                    }while(statusPay!=true);  
                                    selBuy = 3;
                                }
                            }
                        }while(selBuy != 3 && again != "N");
                    }else if(mainMenu==4){
                        //Pre-Order Book
                        int selPre=0;
                        string again;
                        do{
                            again="";
                            cout<<"======================================"<<endl;
                            cout<<"             Pre-Order Book"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"1. Select Category Book"<<endl;
                            cout<<"2. Search Book"<<endl;
                            cout<<"3. Back to main menu"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"Select choices: ";
                            cin>>selPre;
                            if(selPre == 1){
                                do{
                                    ST.ReadFile("MenuCate.txt");
                                    cout<<"Select Menu(1-11): ";
                                    cin>>menuCate;
                                    cout<<endl;
                                    if(menuCate > 0 && menuCate < 11){
                                        //show category
                                        ST.SelectCategoryPreBook(menuCate);
                                        cout<<"Do you want to pre-order book now? (Y/N): ";
                                        cin>>ans;
                                        if(ans=="Y"){
                                            check = "in";
                                        }
                                    }
                                    else{
                                        ans = "Y";
                                        check = "out";
                                    }
                                }while(ans!="Y");
                            }else if(selPre==2){
                                do{
                                    cout<<"Enter Name Book: ";
                                    cin.ignore();
                                    getline(cin,namebook);
                                    ST.SearchPreBook(namebook);
                                    cout<<"Do you want to pre-order book now? (Y/N): ";
                                    cin>>ans;
                                }while(ans!="Y");
                            }
                            if(ans == "Y" && check != "out"){
                                cout<<"Enter id book:";
                                cin>>idBook;
                                ST.PreBook(M,idBook);
                                cout<<"Do you want to Pre-Order more books? (Y/N) :"; //Y back to rent book 
                                cin>>again;
                                if(again=="N"){
                                    do{
                                        cout << " --------------------------------------------------------- " <<endl;
                                        cout << " =================Pay Pre-Order Book====================== " <<endl;
                                        cout << "Enter ID CreditCard : " ;
                                        cin >> Credit;
                                        statusPay = ST.PayPreBook(M,Credit);
                                        if(statusPay==true){
                                            cout << " --------------------------------------------------------- " <<endl;
                                            cout<<"\t\t\t\t\tSuccess!!!"<<endl;
                                            cout << " --------------------------------------------------------- " <<endl;
                                            ST.SavePreBookReport();
                                        }
                                    }while(statusPay!=true);  
                                    selPre = 3;
                                }
                            }
                        }while(selPre != 3 && again != "N");
                    }else if(mainMenu!=5){
                        cout << "Please fill in the correct information!!!!!" << endl;
                    }
                }while(mainMenu!=5);
            }else if(idCheck=="12"){
                M = L.getMember(id);
                check = " ";
                ans = " ";
                cout<<"M: "<<M.getCredit()<<endl;
                do{
                    mainMenu=0;
                    cout << "=====================================" << endl; //main manu
                    cout << "                 Menu                " << endl;
                    cout << "=====================================" << endl;
                    cout << " 1. Search Book" << endl
                        // << " 2. Rent Book" << endl
                         << " 2. Buy Book" << endl
                         << " 3. Pre-Order Book" << endl
                         << " 4. Log Out" << endl;
                    cout << "=====================================" << endl;
                    cout << "Select Menu: " ;
                    cin >> mainMenu;
                    if(mainMenu==1){
                        //Search Book
                        cout<<"Enter Name Book: ";
                        cin.ignore();
                        getline(cin,namebook);
                        ST.SearchBook(namebook);
                    }/*else if(mainMenu==2){
                        int selRent=0;
                        string again="";
                        do{
                            //Rent Book
                            again="";
                            cout<<"======================================"<<endl;
                            cout<<"              Rent Book"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"1. Select Category Book"<<endl;
                            cout<<"2. Search Book"<<endl;
                            cout<<"3. Back to main menu"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"Select choices: ";
                            cin>>selRent;
                            if(selRent == 1){
                                do{
                                    ST.ReadFile("MenuCate.txt");
                                    cout<<"Select Menu(1-11): ";
                                    cin>>menuCate;
                                    cout<<endl;
                                    if(menuCate > 0 && menuCate < 11){
                                        //show category
                                        ST.SelectCategoryRentBook(menuCate);
                                        cout<<"Do you want to rent book now? (Y/N): ";
                                        cin>>ans;
                                        if(ans=="Y"){
                                            check = "in";
                                        }
                                    }
                                    else{
                                        ans = "Y";
                                        check = "out";
                                    }
                                }while(ans!="Y");
                            }else if(selRent==2){
                                do{
                                    cout<<"Enter Name Book: ";
                                    cin.ignore();
                                    getline(cin,namebook);
                                    ST.SearchBook(namebook);
                                    cout<<"Do you want to rent book now? (Y/N): ";
                                    cin>>ans;
                                }while(ans!="Y");

                            }
                            if(ans == "Y" && check != "out"){
                                cout<<"Enter id book:";
                                cin>>idBook;
                                ST.RentBook(M,idBook);
                                cout<<"Do you want to rent more books? (Y/N) :"; //Y back to rent book 
                                cin>>again;
                                if(again=="N"){
                                    do{
                                        cout << " --------------------------------------------------------- " <<endl;
                                        cout << " =================Pay Rent Book=================== " <<endl;
                                        cout << "Enter ID CreditCard : " ;
                                        cin >> Credit;
                                        statusPay = ST.PayRentBook(M,Credit);
                                        if(statusPay==true){
                                            cout << " --------------------------------------------------------- " <<endl;
                                            cout<<"\t\t\t\t\tSuccess!!!"<<endl;
                                            cout << " --------------------------------------------------------- " <<endl;
                                            ST.SaveRentBookReport();
                                        }
                                    }while(statusPay!=true);                                    
                                    selRent = 3;
                                }
                            }
                            //selRent == 3 back main menu
                        }while(selRent != 3);
                    }*/else if(mainMenu==2){
                        //Buy Book
                        int selBuy=0;
                        string again;
                        do{
                            again="";
                            cout<<"======================================"<<endl;
                            cout<<"                Buy Book"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"1. Select Category Book"<<endl;
                            cout<<"2. Search Book"<<endl;
                            cout<<"3. Back to main menu"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"Select choices: ";
                            cin>>selBuy;
                            if(selBuy == 1){
                                //show category
                                do{
                                    ST.ReadFile("MenuCate.txt");
                                    cout<<"Select Menu(1-11): ";
                                    cin>>menuCate;
                                    cout<<endl;
                                    if(menuCate > 0 && menuCate < 11){
                                        //show category
                                        ST.SelectCategoryBuyBook(menuCate);
                                        cout<<"Do you want to buy book now? (Y/N): ";
                                        cin>>ans;
                                        if(ans=="Y"){
                                            check = "in";
                                        }
                                    }
                                    else{
                                        ans = "Y";
                                        check = "out";
                                    }
                                }while(ans!="Y");
                            }else if(selBuy==2){
                                //search
                                do{
                                    cout<<"Enter Name Book: ";
                                    cin.ignore();
                                    getline(cin,namebook);
                                    ST.SearchBook(namebook);
                                    cout<<"Do you want to buy book now? (Y/N): ";
                                    cin>>ans;
                                }while(ans!="Y");
                            }
                            if(ans == "Y" && check != "out"){
                                cout<<"Enter id book:";
                                cin>>idBook;
                                ST.BuyBook(M,idBook);
                                cout<<"Do you want to buy more books? (Y/N) :"; //Y back to rent book 
                                cin>>again;
                                if(again=="N"){
                                    do{
                                        cout << " --------------------------------------------------------- " <<endl;
                                        cout << " =================Pay Buy Book=================== " <<endl;
                                        cout << "Enter ID CreditCard : " ;
                                        cin >> Credit;
                                        statusPay = ST.PayBuyBook(M,Credit);
                                        if(statusPay==true){
                                            cout << " --------------------------------------------------------- " <<endl;
                                            cout<<"\t\t\t\t\tSuccess!!!"<<endl;
                                            cout << " --------------------------------------------------------- " <<endl;
                                            ST.SaveBuyBookReport();
                                        }
                                    }while(statusPay!=true);  
                                    selBuy = 3;
                                }
                            }
                        }while(selBuy != 3 && again != "N");
                    }else if(mainMenu==3){
                        //Pre-Order Book
                        int selPre=0;
                        string again;
                        do{
                            again="";
                            cout<<"======================================"<<endl;
                            cout<<"             Pre-Order Book"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"1. Select Category Book"<<endl;
                            cout<<"2. Search Book"<<endl;
                            cout<<"3. Back to main menu"<<endl;
                            cout<<"======================================"<<endl;
                            cout<<"Select choices: ";
                            cin>>selPre;
                            if(selPre == 1){
                                do{
                                    ST.ReadFile("MenuCate.txt");
                                    cout<<"Select Menu(1-11): ";
                                    cin>>menuCate;
                                    cout<<endl;
                                    if(menuCate > 0 && menuCate < 11){
                                        //show category
                                        ST.SelectCategoryPreBook(menuCate);
                                        cout<<"Do you want to pre-order book now? (Y/N): ";
                                        cin>>ans;
                                        if(ans=="Y"){
                                            check = "in";
                                        }
                                    }
                                    else{
                                        ans = "Y";
                                        check = "out";
                                    }
                                }while(ans!="Y");
                            }else if(selPre==2){
                                do{
                                    cout<<"Enter Name Book: ";
                                    cin.ignore();
                                    getline(cin,namebook);
                                    ST.SearchPreBook(namebook);
                                    cout<<"Do you want to pre-order book now? (Y/N): ";
                                    cin>>ans;
                                }while(ans!="Y");
                            }
                            if(ans == "Y" && check != "out"){
                                cout<<"Enter id book:";
                                cin>>idBook;
                                ST.PreBook(M,idBook);
                                cout<<"Do you want to Pre-Order more books? (Y/N) :"; //Y back to rent book 
                                cin>>again;
                                if(again=="N"){
                                    do{
                                        cout << " --------------------------------------------------------- " <<endl;
                                        cout << " =================Pay Pre-Order Book====================== " <<endl;
                                        cout << "Enter ID CreditCard : " ;
                                        cin >> Credit;
                                        statusPay = ST.PayPreBook(M,Credit);
                                        if(statusPay==true){
                                            cout << " --------------------------------------------------------- " <<endl;
                                            cout<<"\t\t\t\t\tSuccess!!!"<<endl;
                                            cout << " --------------------------------------------------------- " <<endl;
                                            ST.SavePreBookReport();
                                        }
                                    }while(statusPay!=true);  
                                    selPre = 3;
                                }
                            }
                        }while(selPre != 3 && again != "N");
                    }else if(mainMenu!=4){
                        cout << "Please fill in the correct information!!!!!" << endl;
                    }
                }while(mainMenu!=4);
            }else if(idCheck=="13"){
                int menuStaff=0;
                S = L.getStaff(id);
                do{
                    cout << "======================================" << endl;
                    cout << "                Menu                  " << endl;
                    cout << "======================================" << endl;
                    cout << " 1. Search Book" << endl
                        << " 2. Add Book" << endl
                        << " 3. Show Information Report" << endl
                        << " 4. Log Out" << endl;
                    cout << "=====================================" << endl;
                    cin >> menuStaff;
                    if(menuStaff==1){
                        //Search Book
                        cout << "======================================" << endl;
                        cout << "            Search Book               " << endl;
                        cout << "======================================" << endl;
                        cout << "\t\tEnter Name Book: "<<endl;
                        cin.ignore();
                        getline(cin,namebook);
                        ST.SearchBook(namebook);
                    }else if(menuStaff==2){
                        //Add Book                     
                        string IdBook,name,aut,y,c;
	                    double rent,buy,pre;
	                    int numBook,numid,numy;
                        // Enter num book to add
                        //for
                        cout<<"Enter num of book for add books: ";
                        cin>>numBook;
                        for(int i=0;i<numBook;i++){
                            cout<< "idBook: ";
                            cin >> idBook;
                            numid = idBook.length();
                            cout << "NameBook: ";
                            cin.ignore();
                            getline(cin,name);
                            cout << "Author: ";
                            cin.ignore();
                            getline(cin,aut);
                            cout << "year: ";
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
                            }
                            if(numy != 4){
                                cout << "You entered incorrect year.Please enter again." << endl;
                            }
                        ST.AddBook(idBook,name,aut,y,c,rent,buy,pre); 
                        }
                    }else if(menuStaff==3){
                        int selShow=0,m=0;
                        //Show Information Report
                        do{
                            cout << "======================================" << endl;
                            cout << "           Show Report                " << endl;
                            cout << "======================================" << endl;
                            cout << " 1. Rent information report" << endl
                                << " 2. Buy information report" << endl
                                << " 3. Pre-order information repor" << endl
                                << " 4. Return to main manu" << endl;
                            cout << "=====================================" << endl;
                            cin>>selShow;
                            //show 1-12 month
                                                    
                            if(selShow==1){
                                cout << "Enter month: ";
                                cin>>m;
                                S.showRentBookReport(m);

                            }else if(selShow==2){
                                cout << "Enter month: ";
                                cin>>m;
                                S.showBuyBookReport(m);
                            }else if(selShow==3){
                                cout << "Enter month: ";
                                cin>>m;
                                S.showPreOrderBookReport(m);
                            }else if(selShow!=4){
                                cout << "Wrong Information!!!!!!" << endl;
                            }
                        }while(selShow != 4);
                    }else if(menuStaff!=4){
                        cout << "Wrong Information!!!!!!" << endl;
                    }
                }while(menuStaff!=4);
            }
        }
    }while(menu!=3);
    return 0;    
}