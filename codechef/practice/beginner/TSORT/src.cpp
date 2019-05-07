/*
	N,K <= 10^7

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int T,S;
	vector<int> L;
	cin>>S;
	while(S--){
		cin>>T;
		L.push_back(T);
	}
	std::sort(L.begin(),L.end());
	for(int i=0; i < L.size(); i++){
		cout<<L[i]<<endl;
	}
}
