#include "LoginController.h"

LoginController::LoginController(){
    MemberList = new DbLinkedList();
    StaffList = new DbLinkedList();
}
Member LoginController::getMember(string id){
    return MemberList->getMember(id);
}
Staff LoginController::getStaff(string id){
    return StaffList->getStaff(id);
}
bool LoginController::SearchUser(string id, string pass){
    if(MemberList->LoginMember(id, pass) == false && StaffList->LoginStaff(id, pass) == false){
        cout << "\tinvalid Username or Password" << endl
			<< "\t!!!!!Invalid Username or Password!!!!" << endl;
        return false;
    }else if(MemberList->LoginMember(id, pass) == true){
        cout << "\tLogin Successfully" << endl;
        return true;
    }else if(StaffList->LoginStaff(id, pass) == true){
        cout << "\tLogin Successfully" << endl;
        return true;
    }
}
void LoginController::readfileMember(){
    Member m;
    string filein,Surname,Lastname,IdMember,password,Status;
	ifstream infile;
	infile.open("Member.dat", ios::in);
	if(infile.fail()){
		cout << "Not have file." << endl;
	}else{
		while(getline(infile, filein)){
            Surname = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            Lastname = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            IdMember = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            password = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            Status = filein.substr(0, filein.length());
			    filein.erase(0, filein.length());
            m.SetMember(Surname,Lastname,IdMember,password,Status);
            MemberList->AddMember(m);
    	}
	}
	infile.close();
}
void LoginController::readfileStaff(){
    Staff s;
    string filein, IdStaff,password;
	ifstream infile;
	infile.open("Staff.dat", ios::in);
	if(infile.fail()){
		cout << "Not have file." << endl;
	}else{
		while(getline(infile, filein)){
            IdStaff = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            password = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            s.SetStaff(IdStaff,password);
            StaffList->AddStaff(s);
    	}
	}
	infile.close();
}
LoginController::~LoginController(){
    MemberList = NULL;
}