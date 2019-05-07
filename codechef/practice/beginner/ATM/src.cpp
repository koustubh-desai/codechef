/*
	N,K <= 10^7

*/
#include <iostream>
#include <iomanip>
using namespace std;
double execute(int,double);
int main(void) 
{
	// ios_base::sync_with_stdio(false); 
	// cin.tie(NULL);
	double balance;
	int withdraw;
	cin>>withdraw;
	cin>>balance;
	balance = (
		balance >= 0 &&
		balance <= 2000 &&
		withdraw > 0 &&
		withdraw <= balance - 0.5 &&
		withdraw%5==0
	)?execute(withdraw,balance):balance;
	cout<<fixed<<setprecision(2)<<balance;
	return 0;
}

double execute(int draw,double bal){
	if(draw%5==0) {return bal-(draw+0.5);}
	return bal;
}
