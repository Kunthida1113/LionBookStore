#include "Bill.h"> 
	Bill::Bill(){
		IDBill = "";
		amountOfMoney = 0;
	}

	void Bill::setBill(){
		
	}
	  
	double Bill::Calculate(){
	 	double total;
	 	
	 	
	 	return total;
	}

	double Bill::CalculateRent(DbLinkedList * L){
	  	int size = 0;
	  	float total;
	  	Book b;
	  	size = L->size();
	  	for(int i=0;i<size;i++){
	  		b = L->getBook();
	  		total += b.getRentPrice();
		  }
	return total;
	}
	  
	double Bill::CalculateBuy(DbLinkedList * L){
	  	int size = 0;
	  	float total;
	  	Book b;
	  	size = L->size();
	  	for(int i=0;i<size;i++){
	  		b = L->getBook();
	  		total += b.getBuyPrice();
		  }
	return total;	
	}
	  
	double Bill::CalculatePre(DbLinkedList * L){
	  	int size = 0;
	  	float total;
	  	Book b;
	  	size = L->size();
	  	for(int i=0;i<size;i++){
	  		b = L->getBook();
	  		total += b.getPrePrice();
		  }
	return total;
	}
	  
