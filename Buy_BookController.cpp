#include"Buy_BookController.h"

Book Buy_BookController::SelectCategoryBook(){
	
}

Book Buy_BookController::SerachBook(string NameBook){
	ifstream BookFile("All_Book.txt",ios::in);
//	int len_name;
	string idbook,book,author,year,cate,r_price,b_price,p_price;
	string id,namebook,au,ye,cat,r,b;
//	len_name = NameBook.length();
//	len_name = len_name-1;
	if(BookFile.is_open()){
		while(getline(BookFile,line)){
			idbook = line.substr(0,line.find(","));
			line.erase(0,line.find(",")+1);
			book = line.substr(0,line.find(","));
			line.erase(0,line.find(",")+1);
			author = line.substr(0,line.find(","));
			line.erase(0,line.find(",")+1);
			year = line.substr(0,line.find(","));
			line.erase(0,line.find(",")+1);
			cate = line.substr(0,line.find(","));
			line.erase(0,line.find(",")+1);
			r_price = line.substr(0,line.find(","));
			line.erase(0,line.find(",")+1);
			b_price = line.substr(0,line.find(","));
			line.erase(0,line.find(",")+1);
			if(book == NameBook){
				id = idbook;
				namebook = book;
				au = author;
				ye = year;
				cat = cate;
				
				stringstream rent(r_price);
				rent >> r;
				
				stringstream buy(b_price);
				buy >> b;
				
				p_price = (b * 49)/100;				
				
			}	
		}
		BookFile.close();
	}else{
		cout<<"Can not open file"<<endl;
	}
	
	Book sum(id,namebook,au,year,cat,r,b,p_price);
	return sum;
}

Book Buy_BookController::BuyBook(string IdBook){
	
}

double Buy_BookController::Calculate(Book b){
	double sum;
	sum = b.getBuyPrice() * 1;
	
	return sum;
}

bool Buy_BookController::Pay(string AmountofMoney,string IDCreditCard,string IDBill){
	
}
