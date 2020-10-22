#include "BookStoreController.h"
BookStoreController::BookStoreController(){
    BookList = new DbLinkedList();
    RentBookList = new DbLinkedList();
}
BookStoreController::~BookStoreController(){
    BookList = NULL;
    RentBookList = NULL;
}
void BookStoreController::ReadFile(string nameFile){
    string line;
    ifstream ReadFile(nameFile,ios::in);
    if(ReadFile.is_open()){
        while(getline(ReadFile,line)){
            cout<<"\t\t\t"<<line<<endl;
        }
        ReadFile.close();
    }else{
        cout<<"Can not open file"<<endl;
    }
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
    Book b;
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

void BookStoreController::RentBook(Member m,string IdBook){
    Book b;
    b = BookList->getBook(IdBook);
    if(b.getIdBook()!=IdBook){
        cout<<"Don't have this book in store."<<endl;
    }else{
        RentBookList->AddInfo(m,b);
        ShowRentBookList();
    }
    //return b;
}
void BookStoreController::ShowRentBookList(){
    int size=0;
    Book b;
    size = RentBookList->size();
    cout<<"================================================================================================================="<<endl;
    cout<<"\t\t\t\t\t\tRent List"<<endl;
    cout<<"================================================================================================================="<<endl;
    cout<<left<<setw(10)<<"No."<<left<<setw(20)<<"ID Books"<<left<<setw(30)<<"Books Name"<<left<<setw(20)<<"Author"<<left<<setw(10)<<"Price"<<left<<setw(15)<<"Quantity"<<left<<setw(10)<<"Sum"<<endl;
    cout<<"================================================================================================================="<<endl;
    for(int i=1;i<=size;i++){
        b = RentBookList->getBook(i);
        cout<<left<<setw(10)<<i<<left<<setw(20)<<b.getIdBook()<<left<<setw(30)<<b.getNameBook()
        <<left<<setw(20)<<b.getAuthor()<<left<<setw(10)<<b.getRentPrice()<<left<<setw(15)<<"  1"
        <<left<<setw(10)<<b.getRentPrice()<<endl;
    }
    cout<<"================================================================================================================="<<endl;
}

void BookStoreController::BuyBook(Member m,string IdBook){
    Book B;
    B = BookList->getBook(IdBook);
    if(B.getIdBook()!=IdBook){
        cout<<"Don't have this book in store."<<endl;
    }else{
        BuyBookList->AddInfo(m,b);
        ShowBuytBookList();
    };
}

void BookStoreController::ShowBuyBookList();{
	int size=0;
    	Book b;
    	size = BuyBookList->size();
   	cout<<"================================================================================================================="<<endl;
   	cout<<"\t\t\t\t\t\tBuy List"<<endl;
    	cout<<"================================================================================================================="<<endl;
    	cout<<left<<setw(10)<<"No.";
	cout<<left<<setw(20)<<"ID Books";
	cout<<left<<setw(30)<<"Books Name";
	cout<<left<<setw(20)<<"Author";
	cout<<left<<setw(10)<<"Price";
	cout<<left<<setw(15)<<"Quantity";
	cout<<left<<setw(10)<<"Sum"<<endl;
    	cout<<"================================================================================================================="<<endl;
    	for(int i=1;i<=size;i++){
        	b = BuyBookList->getBook(i);
        	cout<<left<<setw(10)<<i;
		cout<<left<<setw(20)<<b.getIdBook();
		cout<<left<<setw(30)<<b.getNameBook();
        	cout<<left<<setw(20)<<b.getAuthor();
		cout<<left<<setw(10)<<b.getRentPrice();
		cout<<left<<setw(15)<<"  1"
        	cout<<left<<setw(10)<<b.getRentPrice()<<endl;
    	}
    	cout<<"================================================================================================================="<<endl;
}

void BookStoreController::PreBook(Member m,string IdBook){
    Book B;
    B = BookList->getBook(IdBook);
    if(B.getIdBook()!=IdBook){
        cout<<"Don't have this book in store."<<endl;
    }else{
        PreBookList->AddInfo(m,b);
        ShowPreBookList();
    };
}

void BookStoreController::ShowPreBookList();{
	int size=0;
    	Book b;
    	size = PreBookList->size();
   	cout<<"================================================================================================================="<<endl;
   	cout<<"\t\t\t\t\t\tPreOrder List"<<endl;
    	cout<<"================================================================================================================="<<endl;
    	cout<<left<<setw(10)<<"No.";
	cout<<left<<setw(20)<<"ID Books";
	cout<<left<<setw(30)<<"Books Name";
	cout<<left<<setw(20)<<"Author";
	cout<<left<<setw(10)<<"Price";
	cout<<left<<setw(15)<<"Quantity";
	cout<<left<<setw(10)<<"Sum"<<endl;
    	cout<<"================================================================================================================="<<endl;
    	for(int i=1;i<=size;i++){
        	b = PreBookList->getBook(i);
        	cout<<left<<setw(10)<<i;
		cout<<left<<setw(20)<<b.getIdBook();
		cout<<left<<setw(30)<<b.getNameBook();
        	cout<<left<<setw(20)<<b.getAuthor();
		cout<<left<<setw(10)<<b.getRentPrice();
		cout<<left<<setw(15)<<"  1"
        	cout<<left<<setw(10)<<b.getRentPrice()<<endl;
    	}
    	cout<<"================================================================================================================="<<endl;
}


void BookStoreController::SaveRentBookReport(){
    Member m;
    Book b;
    string tempMonth,tempDay,tempYear,DateIn,timeIn,f;
	int length=0,check=0;
	unsigned int find =0;    	
    time_t now = time(0);
	string dt = ctime(&now);
	dt.erase(0,dt.find(' ')+1);
	length = dt.length();
	for(int i=0;i<length;i++){
		find = dt.find(' ');
		if(find!=0){
			check++;
			if(check==1){
				tempMonth = dt.substr(0,find);
				dt.erase(0,find+1);
			}else if(check==2){
					tempDay = dt.substr(0,find);
					dt.erase(0,find+1);
			}else if(check==3){
					timeIn = dt.substr(0,find);
					dt.erase(0,find-1);
			}else if(check==4){
					tempYear = dt.substr(2,4);
					dt.erase(0,length);
			}
		}
	}

	DateIn = tempDay+"/"+tempMonth+"/"+tempYear;

    int size=0;
    size = RentBookList->size();
    ofstream writeFile;
    writeFile.open("RentBookReport.txt",ios::app);
    if(writeFile.is_open()){
        for(int i=1;i<=size;i++){
            m = RentBookList->getMember(i);
            b = RentBookList->getBook(i);
            writeFile<<","<<m.getId()<<","<<m.getName()<<","<<b.getNameBook()<<","
            <<b.getRentPrice()<<","<<DateIn<<"\n";
        }
        writeFile.close();
    }else{
        cout<<"Can not open file"<<endl;
    }
}

void BookStoreController::SaveBuyBookReport(){
    Member m;
    Book b;
    string tempMonth,tempDay,tempYear,DateIn,timeIn,f;
	int length=0,check=0;
	unsigned int find =0;    	
    time_t now = time(0);
	string dt = ctime(&now);
	dt.erase(0,dt.find(' ')+1);
	length = dt.length();
	for(int i=0;i<length;i++){
		find = dt.find(' ');
		if(find!=0){
			check++;
			if(check==1){
				tempMonth = dt.substr(0,find);
				dt.erase(0,find+1);
			}else if(check==2){
					tempDay = dt.substr(0,find);
					dt.erase(0,find+1);
			}else if(check==3){
					timeIn = dt.substr(0,find);
					dt.erase(0,find-1);
			}else if(check==4){
					tempYear = dt.substr(2,4);
					dt.erase(0,length);
			}
		}
	}

	DateIn = tempDay+"/"+tempMonth+"/"+tempYear;

    int size=0;
    size = BuyBookList->size();
    ofstream writeFile;
    writeFile.open("BuyBookReport.txt",ios::app);
    if(writeFile.is_open()){
        for(int i=1;i<=size;i++){
            m = BuyBookList->getMember(i);
            b = BuyBookList->getBook(i);
            writeFile<<","<<m.getId()<<","<<m.getName()<<","<<b.getNameBook()<<","
            <<b.getBuyPrice()<<","<<DateIn<<"\n";
        }
        writeFile.close();
    }else{
        cout<<"Can not open file"<<endl;
    }
}

void BookStoreController::SavePreBookReport(){
    Member m;
    Book b;
    string tempMonth,tempDay,tempYear,DateIn,timeIn,f;
	int length=0,check=0;
	unsigned int find =0;    	
    time_t now = time(0);
	string dt = ctime(&now);
	dt.erase(0,dt.find(' ')+1);
	length = dt.length();
	for(int i=0;i<length;i++){
		find = dt.find(' ');
		if(find!=0){
			check++;
			if(check==1){
				tempMonth = dt.substr(0,find);
				dt.erase(0,find+1);
			}else if(check==2){
					tempDay = dt.substr(0,find);
					dt.erase(0,find+1);
			}else if(check==3){
					timeIn = dt.substr(0,find);
					dt.erase(0,find-1);
			}else if(check==4){
					tempYear = dt.substr(2,4);
					dt.erase(0,length);
			}
		}
	}

	DateIn = tempDay+"/"+tempMonth+"/"+tempYear;

    int size=0;
    size = PreBookList->size();
    ofstream writeFile;
    writeFile.open("PreBookReport.txt",ios::app);
    if(writeFile.is_open()){
        for(int i=1;i<=size;i++){
            m = PreBookList->getMember(i);
            b = PreBookList->getBook(i);
            writeFile<<","<<m.getId()<<","<<m.getName()<<","<<b.getNameBook()<<","
            <<b.getPrePrice()<<","<<DateIn<<"\n";
        }
        writeFile.close();
    }else{
        cout<<"Can not open file"<<endl;
    }
}

//Book BookStoreController::SearchBook(string NameBook){
//
//}

//double BookStoreController::CalculateBook(Book b){
//	return b.getBuyPrice();
//}
//bool BookStoreController::Pay(string AmountofMoney,string IDCreditCard,string IDBill){
//    
//}
