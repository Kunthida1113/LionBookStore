#include "Bill.h"
Bill::Bill(){
	IDBill = "";
}
void Bill::setIDBill(){
	string id;
	id = runIDBill();
	IDBill = id;
}
void Bill::writeFile(string id,double money){
	ofstream writeFile;
	writeFile.open("Bill.txt",ios::app);
	if(writeFile.fail()){
		cout<<"Can not open file."<<endl;
	}else{
		writeFile << id <<","<<money<<endl;
	}
	writeFile.close();	
}
string Bill::runIDBill(){
	int num = 1000;
	string line,money,id,idBill;
	ifstream infile;
	infile.open("Bill.txt",ios::in);
	if(infile.fail()){
		cout<<"Can not open file."<<endl;
	}else{
		while (getline(infile,line))
		{
			id = line.substr(0,line.find(','));
			line.erase(0,line.find(','));
			money = line.substr(0,line.length());
			line.erase(0,line.length());
			num++;
		}
	}
	num+=1;
	stringstream temp;
	temp<<num;
	idBill = temp.str();
	return idBill;
}
double Bill::Calculate(double money){
	double total =0,VAT=0.07;
	total = money;
	total =  total + (total*VAT);
	return total;
}
double Bill::CalculateRent(DbLinkedList * L){
	int size = 0;
	double total=0,price=0;
	Book b;
	size = L->size();
	for(int i=1;i<=size;i++){
		b = L->getBook(i);
		price = b.getRentPrice();
		total += price;
	}
	return total;
}
double Bill::CalculateBuy(DbLinkedList * L){
	int size = 0;
	double total=0,price=0;
	Book b;
	size = L->size();
	for(int i=1;i<=size;i++){
		b = L->getBook(i);
		price = b.getBuyPrice();
		total += price;
	}
	return total;	  	
}	  
double Bill::CalculatePre(DbLinkedList *L){
	int size = 0;
	double total=0,price=0;
	Book b;
	size = L->size();
	for(int i=1;i<=size;i++){
		b = L->getBook(i);
		price = b.getPrePrice();
		total += price;
	}
	return total;	  	
}
	  
void Bill::ShowRentBill(Member m,DbLinkedList * L){
	int dateTime[3],size=0;
	time_t DateTime = time(0);
	tm* local_time = localtime(&DateTime);
	dateTime[0] = local_time->tm_mday;
	dateTime[1] = 1 + local_time->tm_mon;
	dateTime[2] = 1900 + local_time->tm_year;
	Book book;
	size = L->size();
	string id = runIDBill();
		///////////////////////////////////////////////////////////////////////////////////////////////////
	    cout<<"---------------------------------------------------------------------------------------------------------" << endl;
	    cout<<"\t\t\t\t\t\t         LION BOOKSTORE     "<< endl;
	    cout<<"---------------------------------------------------------------------------------------------------------" << endl;
	    cout<<"\t\t\t\t\t\t         SE#9 : BURAPHA U.     "<< endl;
	    cout<<"\t\t\t\t\t\t         Receipt Bill     "<< endl;
	    cout<<"\t\t\t169 Longhaad Bangsaen Rd. Saensuk, Muang, Chonburi Thailand, 20131  "<< endl;
	    cout<<"\t\t\t\t     	           Tel: (+66) 3810-2571      "<< endl;
	    cout<<"\t\t\t\t                       TAX ID: "<< id << endl; 
		cout<<dateTime[0]<<"/"<<dateTime[1]<<"/"<<dateTime[2];
		cout<<"                                                                          IDMember: "<< m.getId() <<endl;
		cout<<"---------------------------------------------------------------------------------------------------------"<< endl;
	    for(int i = 1;i <= size;i++){
			book = L->getBook(i);
			cout<<i<<" - "<<book.getNameBook()<<" 			  					"<<book.getRentPrice()<<"  BATH"<< endl;	
		}
		cout<<"											AMOUNT : "<<CalculateRent(L)<<" BATH" << endl;
		double net =0;
		net= CalculateRent(L)+(CalculateRent(L)*0.07); 
		cout<<"											NET : "<<net<<endl;
		cout<<"	 									    (Tax included)";
		cout<<endl;
		cout<<"						ENJOY  READING  AND  THANK  YOU  FOR  TRUST			"<<endl;
		writeFile(id,net);
}
void Bill::ShowBuyBill(Member m,DbLinkedList * L){
	int dateTime[3],size;
	time_t DateTime = time(0);
	tm* local_time = localtime(&DateTime);
	dateTime[0] = local_time->tm_mday;
	dateTime[1] = 1 + local_time->tm_mon;
	dateTime[2] = 1900 + local_time->tm_year;
	Book book;
	size = L->size();
	string id = runIDBill();
		///////////////////////////////////////////////////////////////////////////////////////////////////
	    cout<<"---------------------------------------------------------------------------------------------------------" << endl;
	    cout<<"\t\t\t\t\t\t         LION BOOKSTORE     "<< endl;
	    cout<<"---------------------------------------------------------------------------------------------------------" << endl;
	    cout<<"\t\t\t\t\t\t         SE#9 : BURAPHA U.     "<< endl;
	    cout<<"\t\t\t\t\t\t         Receipt Bill     "<< endl;
	    cout<<"\t\t\t169 Longhaad Bangsaen Rd. Saensuk, Muang, Chonburi Thailand, 20131  "<< endl;
	    cout<<"\t\t\t\t     	           Tel: (+66) 3810-2571      "<< endl;
	    cout<<"\t\t\t\t                       TAX ID: "<< id << endl; 
		cout<<dateTime[0]<<"/"<<dateTime[1]<<"/"<<dateTime[2];
		cout<<"                                                                          IDMember: "<< m.getId() <<endl;
		cout<<"---------------------------------------------------------------------------------------------------------";
	for(int i = 1;i <= size;i++){
		book = L->getBook(i);
		cout<<i<<" - "<<book.getNameBook()<<" 			  					"<<book.getBuyPrice()<<"  B."<< endl;	
	}
		cout<<"												    AMOUNT : "<<CalculateBuy(L)<<" BATH" << endl;
		double net =0;
		net= CalculateBuy(L)+(CalculateBuy(L)*0.07); 
		cout<<"													NET : "<<net<<endl;
		cout<<"													(Tax included)";
		cout<<endl;
		cout<<"						ENJOY  READING  AND  THANK  YOU  FOR  TRUST			"<<endl;
		writeFile(id,net);
}
	
void Bill::ShowPreBill(Member m,DbLinkedList * L){
	int dateTime[3],size;
	time_t DateTime = time(0);
	tm* local_time = localtime(&DateTime);
	dateTime[0] = local_time->tm_mday;
	dateTime[1] = 1 + local_time->tm_mon;
	dateTime[2] = 1900 + local_time->tm_year;
	Book book;
	size = L->size();
	string id = runIDBill();	
		///////////////////////////////////////////////////////////////////////////////////////////////////
	    cout<<"---------------------------------------------------------------------------------------------------------" << endl;
	    cout<<"\t\t\t\t\t\t         LION BOOKSTORE     "<< endl;
	    cout<<"---------------------------------------------------------------------------------------------------------" << endl;
	    cout<<"\t\t\t\t\t\t         SE#9 : BURAPHA U.     "<< endl;
	    cout<<"\t\t\t\t\t\t         Receipt Bill     "<< endl;
	    cout<<"\t\t\t169 Longhaad Bangsaen Rd. Saensuk, Muang, Chonburi Thailand, 20131  "<< endl;
	    cout<<"\t\t\t\t     	           Tel: (+66) 3810-2571      "<< endl;
	    cout<<"\t\t\t\t                       TAX ID: "<< id << endl; 
		cout<<dateTime[0]<<"/"<<dateTime[1]<<"/"<<dateTime[2];
		cout<<"                                                                          IDMember: "<< m.getId() <<endl;
		cout<<"---------------------------------------------------------------------------------------------------------";
	for(int i = 1;i <= size;i++){
		book = L->getBook(i);
		cout<<i<<" - "<<book.getNameBook()<<" 			  					"<<book.getPrePrice()<<"  B."<< endl;	
	}
		
		cout<<"												    AMOUNT : "<<CalculatePre(L)<<" BATH" << endl;
		double net =0;
		net= CalculateBuy(L)+(CalculateBuy(L)*0.07); 
		cout<<"													NET : "<<net<<endl;
		cout<<"													(Tax included)";
		cout<<endl;
		cout<<"						ENJOY  READING  AND  THANK  YOU  FOR  TRUST			"<<endl;
		writeFile(id,net);
}
void Bill::ShowRegisterBill(Member m,double money){
	int day, mon, year;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	day = ltm->tm_mday;
	mon = 1 + ltm->tm_mon;
	year = 1900 + ltm->tm_year;  
	string id = runIDBill();
	///////////////////////////////////////////////////////////////////////////////////////////////////
	cout<<"---------------------------------------------------------------------------------------------------------" << endl;
	cout<<"\t\t\t\t\t\t         LION BOOKSTORE     "<< endl;
	cout<<"---------------------------------------------------------------------------------------------------------" << endl;
	cout<<"\t\t\t\t\t\t         SE#9 : BURAPHA U.     "<< endl;
	cout<<"\t\t\t\t\t\t         Receipt Bill     "<< endl;
	cout<<"\t\t\t169 Longhaad Bangsaen Rd. Saensuk, Muang, Chonburi Thailand, 20131  "<< endl;
	cout<<"\t\t\t\t     	           Tel: (+66) 3810-2571      "<< endl;
	cout<<"\t\t\t\t                       TAX ID: "<< id << endl; 
	cout<<"Date: "<<day<<"/"<<mon<<"/"<<year;  
	cout<<"                                                                          IDMember: "<< m.getId() <<endl;
	cout<<"---------------------------------------------------------------------------------------------------------" << endl;
	cout<<"Register VIP Lion  Bookstore                                                 "<< money<<" BATH"<< endl;        
	cout<<"\t\t\t\t\t\t\t\t\t     AMOUNT  : "<< money<<" BATH" << endl;
	cout<<"\t\t\t\t\t\t\t\t\t     TAX: 7%" << endl;
	cout<<"\t\t\t\t\t\t\t\t\t     NET : " << Calculate(money) <<endl;
	cout<<"\t\t\t\tENJOY  READING  AND  THANK  YOU  FOR  TRUST   " <<endl;
	cout<<"---------------------------------------------------------------------------------------------------------" << endl;
	writeFile(id,Calculate(money));
}