#include<iostream>
#include<string>
#include"Staff.h"
#include"DbLinkedList.h"
#include <fstream>
using namespace std;
class RegisterController{
	private:
		class Node{
            public:
            		string Name;
		      string Lastname;
		string password;
		string Type;
                Book B;
                Member M;
                Staff S;
                Node *link;
                Node *plink;
                Node();
                Node(Book b,Member m, Staff s);
                void setBook(Book b);
                void setMember(Member m);
                void setStaff(Staff s);
        };
        Node *head;
        Node *tail;
        int count;
	public:
		void datamember(){
			Node *temp = head;
			fstream infile;
			infile.open("memberdata.txt",ios::trunc|ios::out);
			while(temp !=NULL){
				infile << temp->Name << "," << temp->Lastname <<","<< temp->password << "," <<temp->Type <<endl;
				temp = temp->link; 
			}
			infile.close();
		}
	};
