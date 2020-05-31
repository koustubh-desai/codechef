#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <tuple>
#include <bits/stdc++.h>
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define max(a,b) a>b?a:b
using namespace std;

void takeInputs(){
	
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	/*std::ifstream in("test.txt");
	std::streambuf*cinbuf = std::cin.rdbuf(); // save old buff
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to be in  .txt!
	std::string line;*/
	int N,T;
	
	cin>>T;
	while(T--){
		int curr,prev;
		vector<int> x;
		int count = 0;
		int infectedCount = 1;
		cin>>N;
		while(N--){
			cin>>curr;
			if(++count == 1){
				prev = curr;
				continue;
			}
			
			if(curr-prev<=2) ++infectedCount;
			else{
				x.push_back(infectedCount);
				infectedCount = 1;
			}
			prev = curr;			
			++count;
		}
		x.push_back(infectedCount);
		sort(x.begin(),x.end(),[](int a,int b){return a<b;});
		cout<<x[0]<<" "<<x[x.size() - 1]<<endl;
	}
	return 0;
}
