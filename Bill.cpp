#include "Bill.h"> 
	Bill::Bill(){
		IDBill = "00000000";
		amountOfMoney = 0;
	}

	void Bill::setBill(double money){
	int dateTime[2];
	int num,ID;
	string mount,year,id,billnum,line;
	string bill = "";
			
		time_t DateTime = time(0);
		tm* local_time = localtime(&DateTime);
		dateTime[0] = 1 + local_time->tm_mon;
		dateTime[1] = 1900 + local_time->tm_year;
			
		stringstream m;
		m << dateTime[0];
		mount = m.str();
			
		stringstream y;
		y << dateTime[1];
		year = y.str();
		
		fstream file_bill;
		file_bill.open("Bill.dat",ios::in | ios::app);
		if(myfile.is_open()){
		while(file_bill >> id){
			bill = id.substr(0,2);			
		}
			stringstream geek(bill);
			geek >> num;	
			
			ID = num+ 1;
			if(ID < 10){
				stringstream i;
				i << ID;
				billnum = "0"+i.str();
			}else{
				stringstream i;
				i << ID;
				billnum = i.str();
			}
		file_bill.close();
		
						
		IDBill = billnum+mount+year;
//		cout <<IDBill;
		////////////////////////////////////////////////////////
		stringstream mo;
		mo << money;
		M = mo.str();
		
		file_bill.open("Bill.dat",ios::app);
			file_bill << IDBill << "," << M << endl;
			
		file_bill.close();
				
		}else{
			cout << "FAIL" <<endl;
		}
		
	}
	double Bill::Calculate(){
	 	double total;
	 	double vat;
	 	vat = 0.07;
	 	total = 777.00;
	 	total = total*vat;
	 	return total;
	}

	double Bill::CalculateRent(DbLinkedList * L){
	  	int size = 0;
	  	double total;
	  	Book b;
	  	size = L->size();
	  	
	  	for(int i=0;i<size;i++){
	  		b = L->getBook(i);
	  		total += b.getRentPrice();
		  }
	return total;
	}
	  
	double Bill::CalculateBuy(DbLinkedList * L){
	  	int size = 0;
	  	double total;
	  	Book b;
	  	size = L->size();
	  	
	  	for(int i=0;i<size;i++){
	  		b = L->getBook(i);
	  		total += b.getBuyPrice();
		  }
	return total;	
	}
	  
	double Bill::CalculatePre(DbLinkedList * L){
	  	int size = 0;
	  	double total,money,net;
	  	string line,id;
	  	Book b;
	  	size = L->size();
	  	
	  	for(int i=0;i<size;i++){
	  		b = L->getBook(i);
	  		total += b.getPrePrice();
		  }
	return total;
	}
	  
	void Bill::ShowRent_Bill(Member m,DbLinkedList * L){
		int dateTime[3],size;
		time_t DateTime = time(0);
		tm* local_time = localtime(&DateTime);
		dateTime[0] = local_time->tm_mday;
		dateTime[1] = 1 + local_time->tm_mon;
		dateTime[2] = 1900 + local_time->tm_year;
		Book book;
		size = L->size();
		
		///////////////////////////////////////////////////////////////////////////////////////////////////
		cout<<"								LION  BOOKSTORE					"<< endl;
		cout<<"							      	SE09 : BURAPHA U.					"<< endl;
		cout<<"								  Receipt Bill					"<< endl;
		cout<<"				   169 Longhaad Bangsaen Rd. Saensuk, Muang, Chonburi Thailand, 20131		"<< endl;
		cout<<"							     Tel: (+66) 3810-2571 					"<< endl;
		cout<<"												TAX ID. "<< m.getId() << endl;
		cout<<dateTime[0]<<"/"<<dateTime[1]<<"/"<<dateTime[2<<"/"];
		cout<<"                                                                        "<<IDmember<<endl;
		cout<<"---------------------------------------------------------------------------------------------------------";
	for(int i = 0;i < size;i++){
		book = L->getbook(i);
		cout<<" 01 - "<<book.getNameBook()<<" 			  					"<<book.getRentPrice()<<"  B."<< endl;	
	}
		
		cout<<"												    AMOUNT : "<<amountOfMoney<<" BATH" << endl;
		net = amountOfMoney*0.07; 
		cout<<"													NET : "<<net<<endl;
		cout<<"													(Tax included)";
		cout<<endl;
		cout<<"						ENJOY  READING  AND  THANK  YOU  FOR  TRUST			"endl;;
	
		
	}
	
	void Bill::ShowBuy_Bill(Member m,DbLinkedList * L){
		int dateTime[3],size;
		time_t DateTime = time(0);
		tm* local_time = localtime(&DateTime);
		dateTime[0] = local_time->tm_mday;
		dateTime[1] = 1 + local_time->tm_mon;
		dateTime[2] = 1900 + local_time->tm_year;
		Book book;
		size = L->size();
		
		///////////////////////////////////////////////////////////////////////////////////////////////////
		cout<<"								LION  BOOKSTORE					"<< endl;
		cout<<"							      	SE09 : BURAPHA U.					"<< endl;
		cout<<"								  Receipt Bill					"<< endl;
		cout<<"				   169 Longhaad Bangsaen Rd. Saensuk, Muang, Chonburi Thailand, 20131		"<< endl;
		cout<<"							     Tel: (+66) 3810-2571 					"<< endl;
		cout<<"												TAX ID. "<< m.getId() << endl;
		cout<<dateTime[0]<<"/"<<dateTime[1]<<"/"<<dateTime[2<<"/"];
		cout<<"                                                                        "<<IDmember<<endl;
		cout<<"---------------------------------------------------------------------------------------------------------";
	for(int i = 0;i < size;i++){
		book = L->getbook(i);
		cout<<" 01 - "<<book.getNameBook()<<" 			  					"<<book.getBuyPrice()<<"  B."<< endl;	
	}
		
		cout<<"												    AMOUNT : "<<amountOfMoney<<" BATH" << endl;
		net = amountOfMoney*0.07; 
		cout<<"													NET : "<<net<<endl;
		cout<<"													(Tax included)";
		cout<<endl;
		cout<<"						ENJOY  READING  AND  THANK  YOU  FOR  TRUST			"endl;;
	
		
	}
	
	void Bill::ShowPre_Bill(Member m,DbLinkedList * L){
		int dateTime[3],size;
		time_t DateTime = time(0);
		tm* local_time = localtime(&DateTime);
		dateTime[0] = local_time->tm_mday;
		dateTime[1] = 1 + local_time->tm_mon;
		dateTime[2] = 1900 + local_time->tm_year;
		Book book;
		size = L->size();
		
		///////////////////////////////////////////////////////////////////////////////////////////////////
		cout<<"								LION  BOOKSTORE					"<< endl;
		cout<<"							      	SE09 : BURAPHA U.					"<< endl;
		cout<<"								  Receipt Bill					"<< endl;
		cout<<"				   169 Longhaad Bangsaen Rd. Saensuk, Muang, Chonburi Thailand, 20131		"<< endl;
		cout<<"							     Tel: (+66) 3810-2571 					"<< endl;
		cout<<"												TAX ID. "<< m.getId() << endl;
		cout<<dateTime[0]<<"/"<<dateTime[1]<<"/"<<dateTime[2<<"/"];
		cout<<"                                                                        "<<IDmember<<endl;
		cout<<"---------------------------------------------------------------------------------------------------------";
	for(int i = 0;i < size;i++){
		book = L->getbook(i);
		cout<<" 01 - "<<book.getNameBook()<<" 			  					"<<book.getPrePrice()<<"  B."<< endl;	
	}
		
		cout<<"												    AMOUNT : "<<amountOfMoney<<" BATH" << endl;
		net = amountOfMoney*0.07; 
		cout<<"													NET : "<<net<<endl;
		cout<<"													(Tax included)";
		cout<<endl;
		cout<<"						ENJOY  READING  AND  THANK  YOU  FOR  TRUST			"endl;;
	
		
	}
