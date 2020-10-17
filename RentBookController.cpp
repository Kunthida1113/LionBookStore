#include "RentBookController.h"
RentBookController::RentBookController(){
    BookList = new DbLinkedList();
}
RentBookController::~RentBookController(){
    BookList = NULL;
}
void RentBookController::LoadInfoBook(){
    string line,idBook,nameBook,rentprice,buyprice,preprice;
    int check=0,l=0;
    
}
Book RentBookController::SelectCategoryBook(){

}
Book RentBookController::SerachBook(string NameBook){

}
Book RentBookController::RentBook(string IdBook){

}
double RentBookController::Calculate(Member m,Book b){

}
bool RentBookController::Pay(string AmountofMoney,string IDCreditCard,string IDBill){
    
}