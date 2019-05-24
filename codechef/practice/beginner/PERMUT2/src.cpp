#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define max(a,b) a>b?a:b
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int N,T,temp;
	string s;
	while(1){
		cin>>N;
		if(N==0) break;
		int arr[100001] = {0};
		s="ambiguous";
		rep(i,1,N+1){
			cin>>temp;
			arr[i]=temp;
		}
		rep(i,1,N/2 + 2){
			temp = arr[i];
			//cout<<" num="<<temp<<" pos="<<i<<endl;
			if(arr[temp] != i){
				//cout<<" arr[temp]="<<arr[temp]<<" i="<<i<<endl;
				s = "not ambiguous";
				break;
			}
		}
		cout<<s<<endl;
		//arr[100000]={0};
	}
	return 0;
}