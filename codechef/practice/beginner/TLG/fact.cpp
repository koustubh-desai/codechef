#include <iostream>
using namespace std;
int main(void){
	int N,i,sum;
	cin>>N;
	sum = 0;
	int result = 1;
	for(i=0;i<N/2;i++){
		sum += N-i*2;
		cout<<sum<<"*";
		result*=sum;
	}
	//In case of odd numbers handle one last multiplication
	if(N%2){
		sum = N/2+1;
		cout<<sum<<"*";
		result*=sum;
	}
	cout<<"\n factorial is "<<result;
	return 0;
}