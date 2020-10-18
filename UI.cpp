#include<iostream>
#include"Book.h"
#include"Member.h"
#include"Staff.h"
using namespace std;
class UI{
	private:
		string Name;
		string Lastname;
		string password;
		string Type;
	public:
		void menu(){
			do{
	  cout << " ==================================================="  <<endl;
	  cout << "            Welcome To Lion Book Store              "  <<endl;
	  cout << " ==================================================="  <<endl;
      cout << "                 1. Register                        "  <<endl;
      cout << "                 2. Login                           "  <<endl;
      cout << "                 3. Exit                            "  <<endl;
      cout << " ================================================== "  <<endl;
      cout << " Select Menu :"                                        <<endl;
	  cin >> menu;
	    if(menu==1){
               cout << " Name : " ;
               cin >> Name ;
               cout << " Lastname : ";
               cin >> Lastname;
               cout << "Password : ";
               cin >> password ;
	             }
	    else {
		cout << " Failed Register " <<endl;
		
        }
        if(menu==2){
        	
        	
		}
     }while(menu!=3)
}
		}
};
