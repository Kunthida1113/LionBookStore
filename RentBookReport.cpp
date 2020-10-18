#include "RentBookReport.h"
#include <string>

RentBookReport::Node::Node(){
    link = NULL;
    plink = NULL;
}
RentBookReport::Node::Node(string id,string namebook,string quantity,string dateofrent,string dateofexpire){
    this->IDRent = id;
    this->NameBook = namebook;
    this->Quantity = quantity;
    this->DateOfRent = dateofrent;
    this->DateOfExpire = dateofexpire;
}
RentBookReport::RentBookReport(){
    this->head = NULL;
    this->tail = NULL;
    count = 0;
}
RentBookReport::~RentBookReport(){
    for(int i = 1; i < this->count; i++){
				Node * tmp = this->head;
				this->head = this->head->link;
				delete tmp;
				tmp = NULL;
			}
			this->head = NULL;
			this->tail = NULL;
}
void RentBookReport::SaveReport(Book B,Member m){

}
void RentBookReport::ShowRentBookReport(int month){
    Node *temp = this->head;
    for(int i=0 ; i<count ; i++){
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << left << setw(5) <<"No" ;
        cout << left << setw(15) <<"User";
        cout << left << setw(22) << "Book name" ;
        cout << left << setw(10) << "Price";
        cout << left << setw(11) << "Date of rent";
        cout << left  << "Date of expire" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        for(int i=0 ; i<count ; i++){
            cout << left << setw(5) << i+1 << endl;
            cout << left << setw(15) << temp->IDRent << endl;
            cout << left << setw(22) << temp->NameBook << endl;
            cout << left << setw(10) << temp->Quantity << endl;
            cout << left << setw(11) << temp->DateOfRent << endl;
            cout << left << temp->DateOfExpire << endl;
            temp = temp->link;
        }
    }
}
void RentBookReport::add(string IDRent,string NameBook,string Quantity,string DateOfRent,string DateOdExpire){
    Node *newnode = new Node(IDRent,NameBook,Quantity,DateOfRent,DateOdExpire);
    Node *temp = this->tail;
    if(this->head == NULL){
        this->head = newnode;
        this->tail = newnode;
    }
    else{
        temp->link = newnode;
        newnode->plink = tail;
        this->tail = newnode;
    }
    count++;
}
void RentBookReport::ReadFileRentBook(){
    string IDRent,NameBook,Quantity,DateOfRent,DateOfExpire;
    //int Quantity;
    ifstream readRentBook;
    readRentBook.open("RentBookReport.txt");
    while( !readRentBook.eof() ){
        getline(readRentBook,IDRent,',');
        if(IDRent == ""){
            break;
        }
        getline(readRentBook,NameBook,',');
        getline(readRentBook,Quantity,',');
        getline(readRentBook,DateOfRent,',');
        getline(readRentBook,DateOfExpire,'\n');
        add(IDRent,NameBook,Quantity,DateOfRent,DateOfExpire);
    }
    
}