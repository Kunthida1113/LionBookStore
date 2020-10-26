#include"Staff.h"
string Staff::getId()
{
	return IdStaff;
}
string Staff::getPass()
{
	return password;
}
void Staff::SetStaff(string id, string pass)
{
	IdStaff = id;
	password = pass;
}
void Staff::showRentBookReport(int m){
	R.showRentBookReport(m);
}
void Staff::showBuyBookReport(int m){
	B.showBuyBookReport(m);
}
void Staff::showPreOrderBookReport(int m){
	P.showPreOrderBookReport(m);
}


