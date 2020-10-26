#include "RentBookReport.h"
void RentBookReport::showRentBookReport(int month){
			string IDRent,NameMember,NameBook,DateOfRent,DateOfExpire;
		    double Quantity;
		    string temp="";
		    string ptemp="";
		    double total = 0;
		    string KeepLine;
		    ifstream readRentBook;
		    readRentBook.open("RentBookReport.txt",ios::in);
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		    cout << left << setw(7) <<"No"<< left << setw(15) <<"ID Member";
		    cout << left << setw(35) <<"Name member"<< left << setw(42) << "Book name" ;
		    cout << left << setw(15) << "Price"<< left << setw(22) << "Date of rent";
		    cout << left  << "Date of expire" << endl;
		    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		    int i = 1; 
		    while(getline(readRentBook,KeepLine)){
		        IDRent = KeepLine.substr(0,KeepLine.find(','));
		        KeepLine.erase(0,KeepLine.find(',')+1);
		        NameMember = KeepLine.substr(0,KeepLine.find(','));
		        KeepLine.erase(0,KeepLine.find(',')+1);
		        NameBook = KeepLine.substr(0,KeepLine.find(','));
		        KeepLine.erase(0,KeepLine.find(',')+1);
		        temp = KeepLine.substr(0,KeepLine.find(','));
		        KeepLine.erase(0,KeepLine.find(',')+1);
                //string to int 
		        stringstream geek(temp);
		        geek >> Quantity;
		        DateOfRent = KeepLine.substr(0,KeepLine.find(','));
		        KeepLine.erase(0,KeepLine.find(',')+1);
		        DateOfExpire = KeepLine.substr(0,KeepLine.length());
		        KeepLine.erase(0,KeepLine.length());
		    
		            switch(month){
		                case 1:
		                    ptemp = "Jan";
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(80) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;
		                case 2:
		                    ptemp = "Feb";
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(91) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;		                        
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;
		                case 3:
		                    ptemp = "Mar";
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(91) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;		                        
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;
		                case 4:
		                    ptemp = "Apr";
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(91) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;		                        
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		            
		                    break;
		
		                case 5:
		                    ptemp = "May";
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(91) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;
		                case 6:
		                    ptemp = "Jun" ;
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i;
		                        cout << left << setw(15) << IDRent;
		                        cout << left << setw(17) << NameMember;
		                        cout << left << setw(91) << NameBook;
		                        total += Quantity;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity;
		                        cout << left << setw(23) << DateOfRent;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;		                        
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;
		                case 7:
		                    ptemp = "Jul" ;
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(91) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;		                        
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;
		                case 8:
		                    ptemp = "Aug" ;
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(91) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;		                        
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;		
		                case 9:
		                    ptemp = "Sep" ;
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(91) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;		                        
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;
		                case 10:
		                    ptemp = "Oct" ;
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(60) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;
		                case 11:
		                    ptemp = "Nov" ;
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(91) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;		                        
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;
		                case 12:
		                    ptemp = "Dec" ;
		                    if(ptemp == DateOfRent.substr(3,3)){
		                        cout << left << setw(7) << i ;
		                        cout << left << setw(15) << IDRent ;
		                        cout << left << setw(17) << NameMember ;
		                        cout << left << setw(91) << NameBook ;
		                        total += Quantity ;
		                        cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
		                        cout << left << setw(23) << DateOfRent ;
		                        cout << left << DateOfExpire;
		                        cout << endl;
		                        i++;
		                    }
		                    else{
		                    	//system("cls");
		                    	cout << "Empty" << endl;
							}
		                    break;
		            }
		    }
			cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		    cout << left <<setw(62) <<"Total\t\t\t\t\t\t" << total <<" Bath" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			readRentBook.close();
}
