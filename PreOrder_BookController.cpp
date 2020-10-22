#include"PreOrder_BookController.h"

Book PreOrder_BookController::SelectCategoryBook(){
	
}

Book PreOrder_BookController::SerachBook(string NameBook){
	
}

void PreOrder_BookController::PreOrderBook(string IdBook){
	Book B;
	PreBookList = new DbLinkedList();
	
 	B = BookList->getBook(IdBook);
    	PreBookList->AddBook(B);
}

double PreOrder_BookController::Calculate(Member m,Book b){
	
}

bool PreOrder_BookController::Pay(string AmountofMoney,string IDCreditCard,string IDBill){
	
}
