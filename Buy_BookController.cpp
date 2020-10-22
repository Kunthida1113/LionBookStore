#include"Buy_BookController.h"

Book Buy_BookController::SelectCategoryBook(){

}

Book Buy_BookController::SerachBook(string NameBook){

}

void Buy_BookController::BuyBook(string IdBook){
	Book B;
	BuyBookList = new DbLinkedList();
	
 	B = BookList->getBook(IdBook);
    	BuyBookList->AddBook(B);	
}

double Buy_BookController::Calculate(Book b){
	double sum;
	sum = b.getBuyPrice() * 1;
	
	return sum;
}

bool Buy_BookController::Pay(string AmountofMoney,string IDCreditCard,string IDBill){
	double money;
	
//	stringstream m(AmountofMoney);
//	m >> money;
	
	// Bill ? 
	
}
