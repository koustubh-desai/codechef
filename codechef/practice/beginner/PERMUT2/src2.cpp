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
		if(N == 0) break;
		int arr[100001] = {0};
		int arr2[100001] = {0};
		
		s="ambiguous";
		rep(i,1,N+1){
			cin>>temp;
			arr[i]=temp;
			arr2[temp] = i;
		}
		rep(i,1,N+1){
			if(arr[i] != arr2[i]){
				s = "not ambiguous";
				break;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}