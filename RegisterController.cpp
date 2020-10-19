#include<iostream>
#include"Staff.h"
using namespace std;
class RegisterController{
	private:
		string Name;
		string Lastname;
		string password;
		string Type;
	public:
		void datamember(){
			fstream infile;
			infile.open("memberdata.txt",ios::trunc|ios::out);
			node *temp =head;
			while(temp !=NULL){
				infile << temp->Name << "," << temp->Lastname <<","<< temp->password << "," <<temp->Type <<endl;
				temp = temp->link; 
			}
			infile.close();
		}
