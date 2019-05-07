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
	string S;
	//ostringstream oss;
	cin>>T;
	while(T--){
		cin>>S;
		sum = 0;
		for(int i=0;i<S.length();i++){
			sum+=S[i]-'0';
			
		}
		cout<<sum<<endl;
	}
}
