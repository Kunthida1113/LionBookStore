#include "BookStoreController.h"
BookStoreController::BookStoreController(){
    BookList = new DbLinkedList();
    RentBookList = new DbLinkedList();
}
BookStoreController::~BookStoreController(){
    BookList = NULL;
    RentBookList = NULL;
}
void BookStoreController::LoadInfoBook(){
    Book B;
    string line,idBook,nameBook,author,year,cate,rentPrice,buyPrice,prePrice;
    string tempId;
    double tempRent,tempBuy,tempPre;
    int check=0,length=0,j=0;
    unsigned int find=0;
    ifstream BookFile("All_Book.txt",ios::in);
    if(BookFile.is_open()){
        while(getline(BookFile,line)){
            length = line.length();
            check=0;
            j++;
            for(int i=0;i<length;i++){
                find = line.find(',');
                if(find != 0){
                    check++;
                    if(check==1){
                        idBook = line.substr(0,find);
                        line.erase(0,find+1);
                        tempId = idBook.substr(0,2);
                        //cout<<j<<"\t"<<tempId<<endl;
                        if(tempId=="00"){
                            cate = "Cartoon";
                        }else if(tempId=="01"){
                            cate = "Children and Youth";
                        }else if(tempId=="02"){
                            cate = "Education";
                        }else if(tempId=="03"){
                            cate = "Foreign";
                        }else if(tempId=="04"){
                            cate = "General Knowledge";
                        }else if(tempId=="05"){
                            cate = "Health";
                        }else if(tempId=="06"){
                            cate = "Infotainment & Art";
                        }else if(tempId=="07"){
                            cate = "Literature";
                        }else if(tempId=="08"){
                            cate = "Magazine";
                        }else if(tempId=="09"){
                            cate = "Techno";
                        }
                    }else if(check==2){
                        nameBook = line.substr(0,find);
                        line.erase(0,find+1);
                    }else if(check==3){
                        author = line.substr(0,find);
                        line.erase(0,find+1);
                    }else if(check==4){
                        year = line.substr(0,find);
                        line.erase(0,find+1);
                    }else if(check==5){
                        rentPrice = line.substr(0,find);
                        line.erase(0,find-1);
                        //rentPrice string to double
                        stringstream tmp(rentPrice);
                        tmp>>(tempRent);
                    }else if(check==6){
                        buyPrice = line.substr(2,length);
                        line.erase(0,length);
                         //buyPrice string to double
                        stringstream tmp2(buyPrice);
                        tmp2>>(tempBuy);
                        //calculate prePrice
                        tempPre = tempBuy-(tempBuy*0.25);
                    }//else check
                }//if find
            }//for
            B.SetBook(idBook,nameBook,author,year,cate,tempRent,tempBuy,tempPre);
        //    cout<<B.getId()<<B.getName()<<B.getAuthor()<<B.getYear()<<endl;
            BookList->AddBook(B);
        }//while
        BookFile.close();
    }//if open
    else{
        cout<<"Can not open file"<<endl;
    }//else open
}
void BookStoreController::SelectCategoryBook(){
    int menuCate=0;
    string cate="";
    cout<<"======================================"<<endl;
	cout<<"\t\tCategory Book"<<endl;
    cout<<"======================================"<<endl;
    cout<<"1. Cartoon"<<endl;
    cout<<"2. Children and Youth"<<endl;
    cout<<"3. Education"<<endl;
    cout<<"4. Foreign"<<endl;
    cout<<"5. General Knowledge"<<endl;
    cout<<"6. Health"<<endl;
    cout<<"7. Infotainment & Art"<<endl;
    cout<<"8. Literature"<<endl;
    cout<<"9. Magazine"<<endl;
    cout<<"10. Techno"<<endl;
    cout<<"11. Back to main menu"<<endl;
    cout<<"======================================"<<endl;
    cout<<"Select Menu(1-11): ";
    cin>>menuCate;
    cout<<endl;
    if(menuCate==1){
        cate = "Cartoon";
    }else if(menuCate==2){
        cate = "Children and Youth";
    }else if(menuCate==3){
        cate = "Education";
    }else if(menuCate==4){
        cate = "Foreign";
    }else if(menuCate==5){
        cate = "General Knowledge";
    }else if(menuCate==6){
        cate = "Health";
    }else if(menuCate==7){
        cate = "Infotainment & Art";
    }else if(menuCate==8){
        cate = "Literature";
    }else if(menuCate==9){
        cate = "Magazine";
    }else if(menuCate==10){
        cate = "Techno";
    }
    BookList->ShowCategory(cate);
}
/*
Book BookStoreController::SearchBook(string NameBook){

}
*/
void BookStoreController::RentBook(string IdBook){
    Book b;
    b = BookList->getBook(IdBook);
    RentBookList->AddBook(b);
    
}
/*
double BookStoreController::Calculate(Member m,Book b){

}
bool BookStoreController::Pay(string AmountofMoney,string IDCreditCard,string IDBill){
    
}*/