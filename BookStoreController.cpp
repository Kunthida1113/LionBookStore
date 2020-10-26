#include "BookStoreController.h"
BookStoreController::BookStoreController(){
    BookList = new DbLinkedList();
    RentBookList = new DbLinkedList();
    BuyBookList = new DbLinkedList();
    PreBookList = new DbLinkedList();
    preBookList = new DbLinkedList();
}
BookStoreController::~BookStoreController(){
    BookList = NULL;
    RentBookList = NULL;
    BuyBookList = NULL;
    PreBookList = NULL;
    preBookList = NULL;
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
    double tempRent,tempBuy,tempPre=0.00;
    int check=0,length=0;
    unsigned int find=0;
    ifstream BookFile("All_Book.txt",ios::in);
    if(BookFile.is_open()){
        while(getline(BookFile,line)){
            length = line.length();
            check=0;
            for(int i=0;i<length;i++){
                find = line.find(',');
                if(find != 0){
                    check++;
                    if(check==1){
                        idBook = line.substr(0,find);
                        line.erase(0,find+1);
                        tempId = idBook.substr(0,2);
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
                    }//else check
                }//if find
            B.SetBook(idBook,nameBook,author,year,cate,tempRent,tempBuy,tempPre);
            }//for
            if(B.getBuyPrice()==0 && B.getRentPrice()==0){
                PreBookList->AddBook(B);
            }else{
                BookList->AddBook(B);
            }
        }//while
        BookFile.close();
    }//if open
    else{
        cout<<"Can not open file"<<endl;
    }//else open
}
void BookStoreController::LoadPreBook(){
    Book B;
    string line,idBook,nameBook,author,year,cate,rentPrice,buyPrice,prePrice;
    string tempId;
    double tempRent=0.00,tempBuy=0.00,tempPre=0.00;
    int check=0,length=0;
    unsigned int find=0;
    ifstream BookFile("PreOrderBook.txt",ios::in);
    if(BookFile.is_open()){
        while(getline(BookFile,line)){
            length = line.length();
            check=0;
            for(int i=0;i<length;i++){
                find = line.find(',');
                if(find != 0){
                    check++;
                    if(check==1){
                        idBook = line.substr(0,find);
                        line.erase(0,find+1);
                        tempId = idBook.substr(0,2);
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
                        prePrice = line.substr(0,length);
                        line.erase(0,length);
                         //prePrice string to double
                        stringstream tmp2(prePrice);
                        tmp2>>(tempPre);
                    }
                }//if find
            B.SetBook(idBook,nameBook,author,year,cate,tempRent,tempBuy,tempPre);
            }//for
            preBookList->AddBook(B);
        }//while
        BookFile.close();
    }//if open
    else{
        cout<<"Can not open file"<<endl;
    }//else open   
}
/*void BookStoreController::LoadPreBook(){
    Book B;
    string line,idBook,nameBook,author,year,cate,rentPrice,buyPrice,prePrice;
    string tempId;
    double tempRent=0.00,tempBuy=0.00,tempPre=0.00;
    int check=0,length=0;
    unsigned int find=0;
    ifstream BookFile("PreOrderBook.txt",ios::in);
    if(BookFile.is_open()){
        while(getline(BookFile,line)){
            length = line.length();
            check=0;
            for(int i=0;i<length;i++){
                find = line.find(',');
                if(find != 0){
                    check++;
                    if(check==1){
                        idBook = line.substr(0,find);
                        line.erase(0,find+1);
                        tempId = idBook.substr(0,2);
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
                        prePrice = line.substr(2,length);
                        line.erase(0,length);
                         //prePrice string to double
                        stringstream tmp2(prePrice);
                        tmp2>>(tempPre);
                    }
                }//if find
            B.SetBook(idBook,nameBook,author,year,cate,tempRent,tempBuy,tempPre);
            }//for
            preBookList->AddBook(B);
        }//while
        BookFile.close();
    }//if open
    else{
        cout<<"Can not open file"<<endl;
    }//else open   
    
}*/
void BookStoreController::AddBook(string idBook,string nameBook,string author,string year,string cate,double rentPrice,double buyPrice,double prePrice){
	ofstream myfile;
	myfile.open("All_Book.txt",ios::app);
	
	string cat,rent,buy,pre;
	if(myfile.is_open()){
	stringstream r ;
	r << rentPrice; 
	rent = r.str();
	
	stringstream b ;
	b << buyPrice; 
	buy = b.str();
    
	stringstream p ;
	p << prePrice; 
	pre = p.str();
    Book B;
    B.SetBook(idBook,nameBook,author,year,cate,rentPrice,buyPrice,prePrice);
	myfile << idBook << "," 
	 	   << nameBook << "," 
		   << author << "," 
		   << year << ","
		   << rent << "," 
		   << buy << ","
		   << pre << endl;
    cout<<"==============================================="<<endl;
    cout<<"ID BOOK: "<<B.getIdBook()<<endl;
    cout<<"Name: "<<B.getNameBook()<<endl;
    cout<<"Author: "<<B.getAuthor()<<endl;
    cout<<"Year: "<<B.getYear()<<endl;
    cout<<"Category: "<<B.getCate()<<endl;
    cout<<"Rent Price: "<<B.getRentPrice()<<endl;
    cout<<"Buy Price: "<<B.getBuyPrice()<<endl;
    cout<<"Pre Price: "<<B.getPrePrice()<<endl;
    cout<<"==============================================="<<endl;
	myfile.close();		
	}else{
		cout<<"Can not open file."<<endl;
	}

}
void BookStoreController::SelectCategoryRentBook(int menuCate){
    Book b;
    string cate=" ";
    ReadFile("MenuCate.txt");
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
    if(cate!=" "){
        BookList->ShowRentCategory(cate);
    }
}
void BookStoreController::SelectCategoryBuyBook(int menuCate){
    Book b;
    string cate=" ";
    ReadFile("MenuCate.txt");
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
    if(cate!=" "){
        BookList->ShowBuyCategory(cate);
    }
}
void BookStoreController::SelectCategoryPreBook(int menuCate){
    Book b;
    string cate=" ";
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
    if(cate!=" "){
        PreBookList->ShowPreCategory(cate);
    }
}
void BookStoreController::SearchBook(string NameBook){
    Book B;
    int size=0;
    size = BookList->size();
    for(int i=1;i<=size;i++){
        B = BookList->getBook(i);
        if(B.getNameBook()==NameBook){
		    cout<<B.getIdBook()<<setw(20)<<left<<B.getNameBook()<<setw(20)<<left<<B.getAuthor()<<setw(20)<<left<<B.getRentPrice()<<setw(20)<<left<<B.getBuyPrice()<<endl;
        }
    }
}
void BookStoreController::SearchPreBook(string NameBook){
    Book B;
    int size=0;
    size = PreBookList->size();
    for(int i=1;i<=size;i++){
        B = PreBookList->getBook(i);
        if(B.getNameBook()==NameBook){
		    cout<<B.getIdBook()<<setw(20)<<left<<B.getNameBook()<<setw(20)<<left<<B.getAuthor()<<setw(20)<<left<<B.getRentPrice()<<setw(20)<<left<<B.getBuyPrice()<<endl;
        }
    }
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
void BookStoreController::SaveRentBookReport(){
    Member m;
    Book b;
    string tempMonth,tempUpMonth,tempDay,tempYear,DateIn,DateEx,timeIn,f;
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
    if(tempMonth == "Jan"){
        tempUpMonth = "Feb";
    }else if(tempMonth == "Feb"){
        tempUpMonth = "Mar";
    }else if(tempMonth == "Mar"){
        tempUpMonth = "Apr";
    }else if(tempMonth == "Apr"){
        tempUpMonth = "May";
    }else if(tempMonth == "May"){
        tempUpMonth = "Jun";
    }else if(tempMonth == "Jun"){
        tempUpMonth = "Jul";
    }else if(tempMonth == "Jul"){
        tempUpMonth = "Aug";
    }else if(tempMonth == "Aug"){
        tempUpMonth = "Sep";
    }else if(tempMonth == "Sep"){
        tempUpMonth = "Oct";
    }else if(tempMonth == "Oct"){
        tempUpMonth = "Nov";
    }else if(tempMonth == "Nov"){
        tempUpMonth = "Dec";
    }else if(tempMonth == "Dec"){
        tempUpMonth = "Jan";
        string year = tempYear;
        int y=0;
        stringstream ss(year);
        ss >> y;
        y += 1;
        stringstream temp;
        temp <<y;
        tempYear = temp.str();
    }
	DateIn = tempDay+"/"+tempMonth+"/"+tempYear;
    DateEx = tempDay+"/"+tempUpMonth+"/"+tempYear;
    //write to file
    int size=0;
    size = RentBookList->size();
    ofstream writeFile;
    writeFile.open("RentBookReport.txt",ios::app);
    if(writeFile.is_open()){
        for(int i=1;i<=size;i++){
            m = RentBookList->getMember(i);
            b = RentBookList->getBook(i);
            writeFile<<m.getId()<<","<<m.getName()<<","<<b.getNameBook()<<","
            <<b.getRentPrice()<<","<<DateIn<<","<<DateEx<<"\n";
        }
        writeFile.close();
    }else{
        cout<<"Can not open file"<<endl;
    }
}
void BookStoreController::BuyBook(Member m,string IdBook){
    Book B;
    B = BookList->getBook(IdBook);
    if(B.getIdBook()!=IdBook){
        cout<<"Don't have this book in store."<<endl;
    }else{
        BuyBookList->AddInfo(m,B);
        ShowBuyBookList();
    }
}

void BookStoreController::ShowBuyBookList(){
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
		cout<<left<<setw(10)<<b.getBuyPrice();
		cout<<left<<setw(15)<<"  1";
        	cout<<left<<setw(10)<<b.getBuyPrice()<<endl;
    	}
    	cout<<"================================================================================================================="<<endl;
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
            writeFile<<m.getId()<<","<<m.getName()<<","<<b.getNameBook()<<","
            <<b.getBuyPrice()<<","<<DateIn<<"\n";
        }
        writeFile.close();
    }else{
        cout<<"Can not open file"<<endl;
    }
}
void BookStoreController::PreBook(Member m,string IdBook){
    Book B;
    B = preBookList->getBook(IdBook);
    if(B.getIdBook()!=IdBook){
        cout<<"Don't have this book in store."<<endl;
    }else{
        PreBookList->AddInfo(m,B);
        ShowPreBookList();
    };
}

void BookStoreController::ShowPreBookList(){
	int size=0;
    	Book b;
    	size = PreBookList->size();
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
        	b = PreBookList->getBook(i);
        	cout<<left<<setw(10)<<i;
		cout<<left<<setw(20)<<b.getIdBook();
		cout<<left<<setw(30)<<b.getNameBook();
        	cout<<left<<setw(20)<<b.getAuthor();
		cout<<left<<setw(10)<<b.getPrePrice();
		cout<<left<<setw(15)<<"  1";
        	cout<<left<<setw(10)<<b.getPrePrice()<<endl;
    	}
    	cout<<"================================================================================================================="<<endl;
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
    writeFile.open("PreOrderBookReport.txt",ios::app);
    if(writeFile.is_open()){
        for(int i=1;i<=size;i++){
            m = PreBookList->getMember(i);
            b = PreBookList->getBook(i);
            writeFile<<m.getId()<<","<<m.getName()<<","<<b.getNameBook()<<","
            <<b.getPrePrice()<<","<<DateIn<<"\n";
        }
        writeFile.close();
    }else{
        cout<<"Can not open file"<<endl;
    }
}
void BookStoreController::ShowBooklist(){
    BookList->ShowBookList();
}
void BookStoreController::ShowAllPreBooklist(){
    preBookList->ShowBookList();
}

bool BookStoreController::PayRentBook(Member m,string IDCredit){
    bool check=false;
    if(m.getCredit()==IDCredit){
        Bi->ShowRentBill(m,RentBookList);
        check = true;
    }else{
        cout<<"Please try again"<<endl;
        check = false;
    }
    return check;
}
bool BookStoreController::PayBuyBook(Member m,string IDCredit){
    bool check=false;
    if(m.getCredit()==IDCredit){
        Bi->ShowBuyBill(m,BuyBookList);
        check = true;
    }else{
        cout<<"Please try again"<<endl;
        check = false;
    }
    return check;
}
bool BookStoreController::PayPreBook(Member m,string IDCredit){
    bool check=false;
    if(m.getCredit()==IDCredit){
        Bi->ShowPreBill(m,PreBookList);
        check = true;
    }else{
        cout<<"Please try again"<<endl;
        check = false;
    }
    return check;
}
