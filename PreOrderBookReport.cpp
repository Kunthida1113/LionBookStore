#include "PreOrderBookReport.h"
void PreOrderBookReport::showPreOrderBookReport(int month){
    string IDPre,NameMember,NameBook,DateOfPreOrder;
    int Quantity;
    string temp="",ptemp="";
    int total = 0;
    string KeepLine;
    ifstream ReadPreBook;
    ReadPreBook.open("PreOrderBookReport.txt");
    int i = 1;
    while( getline(ReadPreBook,KeepLine) ){
        IDPre = KeepLine.substr(0,KeepLine.find(','));
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
        total += Quantity ;

        DateOfPreOrder = KeepLine.substr(0,KeepLine.length());
        KeepLine.erase(0,KeepLine.length());

            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << left << setw(7) <<"No" ;
            cout << left << setw(15) <<"ID Member";
            cout << left << setw(35) << "Name member"<< left << setw(60) << "Book name" ;
            cout << left << setw(15) << "Price";
            cout << left << setw(22) << "Date of pre-order" << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            switch(month){
                case 1:
                    ptemp = "Jan" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;
                case 2:
                    ptemp = "Feb" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;
                case 3:
                    ptemp = "Mar" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;
                case 4:
                    ptemp = "Apr" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;

                case 5:
                    ptemp = "May" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;
                case 6:
                    ptemp = "Jun" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;

                case 7:
                    ptemp = "Jul" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;

                case 8:
                    ptemp = "Aug" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;

                case 9:
                    ptemp = "Sep";
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;

                case 10:
                    ptemp = "Oct" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;

                case 11:
                    ptemp = "Nov" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;

                case 12:
                    ptemp = "Dec" ;
                    if(ptemp == DateOfPreOrder.substr(3,3)){
                        cout << left << setw(7) << i ;
                        cout << left << setw(15) << IDPre ;
		                cout << left << setw(17) << NameMember ;
                        cout << left << setw(80) << NameBook ;
 		                total += Quantity ;
		                cout << left << setw(15) << fixed << setprecision(2) << Quantity ;
                        cout << left << setw(23) << DateOfPreOrder << endl;
                        i++;
                    }
                    else{
		                //system("cls");
		                cout << "Empty" << endl;
					}
                    break;
            }
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << left <<setw(67) <<"Total\t\t\t\t\t\t\t\t" << total << endl;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            ReadPreBook.close();
    }
}