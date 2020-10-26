#include "RegisterController.h"
Member RegisterController::Register(string name, string lastname, string pass, string type,string IDCreditCard){
    Member m;
    string idMember = "",status="1",DateReg,DateEx;
    idMember =  SelectTypeMember(type);
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int tempMonth = 0;
    string days,mon,year;
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
            << type <<","
            << status<<",";
            infile <<ltm->tm_mday<<"/"<<ltm->tm_mon+1<<"/"<< 1900 + ltm->tm_year;
                    stringstream dd;
                    dd << ltm->tm_mday; //int
                    days = dd.str(); //แปลงสตริง
                    stringstream mm;
                    mm<< ltm->tm_mon+1; //int
                    mon = mm.str(); //แปลงสตริง
                    stringstream yyear;  
                    yyear<< 1900 + ltm->tm_year; //int
                    year= yyear.str(); //แปลงสตริง
            DateReg = days+"/"+mon+"/"+year;        
            if(type=="VIP"){
            tempMonth = ltm->tm_mon+2;
            tempMonth = tempMonth;
            infile << "," <<ltm->tm_mday<<"/"
                << tempMonth<< "/"
                << 1900 + ltm->tm_year<< endl;
            cout<<"Date Expire: "<<ltm->tm_mday<<"/"<< tempMonth<< "/"<< 1900 + ltm->tm_year<< endl;
                    stringstream dayd;
                    dayd << ltm->tm_mday; //int
                    days = dayd.str(); //แปลงสตริง
                    stringstream monm;
                    monm<< ltm->tm_mon+1; //int
                    mon = monm.str(); //แปลงสตริง
                    stringstream yer;  
                    yer<< 1900 + ltm->tm_year; //int
                    year= yer.str(); //แปลงสตริง
            DateEx =days+"/"+mon+"/"+year;  //วันเดีือนปี หมดอายุ 
            m.SetMember(name,lastname,idMember,pass,type,status,IDCreditCard,DateReg,DateEx);
        }else{
            DateEx = "";
            m.SetMember(name,lastname,idMember,pass,type,status,IDCreditCard,DateReg,DateEx);
            infile << " " << endl;
        } 
	}	
	infile.close();
    return m;
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
bool RegisterController::Pay(Member m, string idCredit){
    double priceOfVIP=777;
	if(m.getCredit() == idCredit){
        Bi->ShowRegisterBill(m,priceOfVIP);
        return true;
	}else{
		return false;
	}

}
