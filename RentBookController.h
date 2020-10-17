#include<iostream>
#include<string>
#include<fstream>
#include"Book.h"
#include"Member.h"
#include"DbLinkedList.h"

class RentBookController{
	private:
		DbLinkedList *BookList;
	public:
		RentBookController();
		~RentBookController();
		void LoadInfoBook();
		Book SelectCategoryBook();
		Book SerachBook(string NameBook);
		Book RentBook(string IdBook);
		double Calculate(Member m,Book b);
		bool Pay(string AmountofMoney,string IDCreditCard,string IDBill);
};
