#include "RegiterController.h"

void RegiterController::Register(string surname, string lastname, string password, string status){
    int num;
    string snum, idMember;   
    num = NumberMember();
    num += 1;
    stringstream ss;
    ss << num;
    snum = ss.str();
    if(status=="General"){
        idMember = "11" + snum;
        status = "General";
    }else if("VIP"){
        idMember = "12" + snum;
        status = "VIP";
    }
    string filein;
	ofstream infile;
	infile.open("Member.dat", ios::app);
	if(infile.fail()){
		cout << "Not have file." << endl;
	}else{
		infile << surname << ","
        << lastname << ","
        << idMember << ","
        << password << ","
        << status << endl;
	}	
	infile.close();
    //Member *M = new Member(surname, lastname, idMember, password, status);
}
int RegiterController::NumberMember(){
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
void RegiterController::SelectTypeMember(string Type){

}
bool RegiterController::Pay(string amount, string idCredit, string idBill){

}