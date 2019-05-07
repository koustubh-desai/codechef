/*
	N,K <= 10^7

*/
#include <iostream>
#include <sstream>
using namespace std;
int main(void) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int T,sum;
	int S1=0,S2=0;
	int P1,P2,lead=0;
	int i=0,diff=0;
	cin>>T;
	while(T--){
		cin>>P1>>P2;
		S1+=P1;S2+=P2;
		//diff=(P1>P2)?P1-P2:P2-P1;
		diff=(S1>S2)?S1-S2:S2-S1;
		if(lead<diff){
			lead = diff;
			i=(S1>S2)?1:2;
		}
	}
	cout<<i<<" "<<lead<<endl;
}
