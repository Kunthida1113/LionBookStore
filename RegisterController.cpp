#include "RegisterController.h"
string RegisterController::Register(string name, string lastname, string pass, string status,string IDCreditCard){
    string idMember = "";
    idMember =  SelectTypeMember(status);
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string filein;
	ofstream infile;
	infile.open("Member.dat", ios::app);
	if(infile.fail()){
		cout << "Not have file." << endl;
	}else{
		infile << name << ","
            << lastname << ","
            << idMember << ","
            << pass << ","
            << IDCreditCard <<","
            << status <<",";
        if(status=="VIP"){
            infile << 1900 + ltm->tm_year << "-"
                << 1 + ltm->tm_mon<< "-"
                << ltm->tm_mday << endl;
        }else{
            infile << " " << endl;
        } 
	}	
	infile.close();
    return idMember;
    //Member *M = new Member(surname, lastname, idMember, password, status);
}
int RegisterController::NumberMember(){
    //เช็กว่ามี Member กี่คน
    string surname, lastname, password, idMember, status;
    string filein;
    int num = 1000;
	ifstream infile;
	infile.open("Member.dat", ios::in);
	if(infile.fail()){
		cout << "Not have file." << endl;
	}else{
		while(getline(infile, filein)){
			surname = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            lastname = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            password = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            idMember = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            num++;
    	}
	}
	infile.close();
    return num;
}
string RegisterController::SelectTypeMember(string Type){
    int num;
    string idMember = "";
    string snum;   
    num = NumberMember();
    num += 1;
    stringstream ss;
    ss << num;
    snum = ss.str();
    if(Type=="General"){
        idMember = "11" + snum;
    }else if(Type=="VIP"){
        idMember = "12" + snum;
    }
    return idMember;

}
bool RegisterController::Pay(string amount, string idCredit, string idBill){

}