#include<iostream>
#include<string>
#include<fstream>
#include "Member.h"
#include "Book.h"
using namespace std;

class RentBookReport{
	private :
		class Node{
				public:
					string IDRent,NameBook,DateOfRent,DateOfExpire,Quantity;
					Node *link;
					Node *plink;
					Node();
					Node(string id,string namebook,string quantity,string dateofrent,string dateofexpire);
			};

		Node *head;
		Node *tail;
		int count;
	
	public :
		RentBookReport();
		~RentBookReport();
		void SaveReport(Book B,Member m);
		void ShowRentBookReport(int month);
		void ReadFileRentBook();
		void add(string IDRent,string NameBook,string Quantity,string DateOfRent,string DateOdExpire);
};
