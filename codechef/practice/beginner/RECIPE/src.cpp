#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep2(i,a,b)  for(int i=a;i<=b;i++)
#define max(a,b) a>b?a:b
using namespace std;
int gcd(int a,int b){
	int r;
	if(a==1 || b==1) return 1;
	// Make a the greatest of two
	if(b>a){
		a += b;
		b = a-b;
		a = a-b;
	}
	r = a%b;
	if(r == 0) return b;
	return gcd(b,r);

}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int N,T,g,num;
	int arr[50];
	cin>>T;
	while(T--){
		cin>>N;
		rep(i,0,N){
			cin>>num;
			arr[i]=num;
		}
		g = arr[0];
		rep(i,1,N){
			if(g==1) break;
			g=gcd(g,arr[i]);
		}
		if(g==1){
			rep(i,0,N){
				cout<<arr[i]<<" ";
			}
		}
		else{
			rep(i,0,N){
				cout<<arr[i]/g<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}