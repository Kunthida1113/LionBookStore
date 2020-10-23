#include "Bill.h"> 
	Bill::Bill(){
		IDBill = "00000000";
		amountOfMoney = 0;
	}

	void Bill::setBill(double money){
		fstream myfile;
		myfile.open("Bill.txt",ios::in|ios::out|ios::app);
		string line;
		string id;
		int num;
		int date[2];
		if(myfile.is_open()){
				while(getline(myfile,line)){
				 id = line.substr(0,2);
				}	
				stringstream numid(id);
				numid >> num;
				
				num = num++;
				time_t date = time(0); 
				tm*local = localtime(&date);
				date[0] = 1+local->tm_mon;
				date[1] = 1900+local->tm_year;
				stringstream mon;
				mon << date[0];
				string mont = mon.str();
				stringstream year;
				year << date[1];
				string yyear = year.str();
				
				stringstream n;
				n << num;
				string nu = n.str();
				IDBill = nu+mont+yyear;
				amountOfMoney = money;
				
				myfile << IDBill << "," << amountOfMoney <<endl;
				myfile.close();
				
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
	  	double total,money;
	  	string line,id;
	  	Book b;
	  	size = L->size();
	  	
	  	for(int i=0;i<size;i++){
	  		b = L->getBook(i);
	  		total += b.getPrePrice();
		  }
	return total;
	}
	  
