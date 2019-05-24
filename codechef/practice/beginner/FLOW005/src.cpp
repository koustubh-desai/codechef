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
	int N,T,notes;
	int denom[6] = {100,50,10,5,2,1};
	cin>>T;
	while(T--){
		cin>>N;
		notes = 0;
		rep(i,0,6){
			if(denom[i]<=N){
				notes += N/denom[i];
				N = N%denom[i];
			}
		}
		cout<<notes<<endl;
	}
	return 0;
}