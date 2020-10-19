#include "LoginController.h"

LoginController::LoginController(){
    MemberList = new DbLinkedList();
}
string LoginController::SearchUser(string id, string pass){
    string member;
    string staff;
    if(MemberList->LoginMember(id, pass) == false /*&& D->LoginStaff(id, pass) == false*/){
        cout << "\t\tinvalid Username or Password" << endl
			<< "\t\t!!!!!Invalid Username or Password!!!!" << endl;
    }else if(MemberList->LoginMember(id, pass) == true){
        cout << "\t\tLogin Successfully" << endl;
        member = id.substr(0, id.find("")+2);
        return member;
    }/*else if(D->LoginStaff(id, pass) == true){
        cout << "\t\tLogin Successfully" << endl;
        staff = id.substr(0, id.find("")+2);
        return staff;
    }*/
}
void LoginController::readfileMember(){
    Member m;
    int j=0;
    string filein,Surname,Lastname,IdMember,password,Status;
	ifstream infile;
	infile.open("Member.dat", ios::in);
	if(infile.fail()){
		cout << "Not have file." << endl;
	}else{
		while(getline(infile, filein)){
            j++;
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
                cout<<j<<endl;
           //     cout<<Surname<<"\t"<<Lastname<<"\t"<<IdMember<<"\t"<<password<<"\t"<<Status<<endl;
            m.SetMember(Surname,Lastname,IdMember,password,Status);
            MemberList->AddMember(m);
            cout<<m.getId()<<"\t"<<m.getPass()<<endl;
    	}
	}
	infile.close();
    cout << IdMember << " " << password << endl;
}
LoginController::~LoginController(){
    MemberList = NULL;
}