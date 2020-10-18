#include "LoginController.h"

LoginController::LoginController(){

}
string LoginController::SearchUser(string id, string pass){
    DbLinkedList *D;
    string member;
    string staff;
    if(D->LoginMember(id, pass) == false && D->LoginStaff(id, pass) == false){
        cout << "\t\tinvalid Username or Password" << endl
			<< "\t\t!!!!!Invalid Username or Password!!!!" << endl;
    }else if(D->LoginMember(id, pass) == true){
        cout << "\t\tLogin Successfully" << endl;
        member = id.substr(0, id.find("")+2);
        return member;
    }else if(D->LoginStaff(id, pass) == true){
        cout << "\t\tLogin Successfully" << endl;
        staff = id.substr(0, id.find("")+2);
        return staff;
    }
}
LoginController::~LoginController(){

}