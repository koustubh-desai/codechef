#include <iostream>
#include <sstream>
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep2(i,a,b)  for(int i=a;i<=b;i++)
#define max(a,b) a>b?a:b
using namespace std;
string pallin(string s){
	if(s.length() <=1 ) return "wins";
	if(s[0] != s[s.length()-1]) return "losses";
	return pallin(s.substr(1,s.length()-2));
	return "wins";
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int N,T;
	cin>>T;
	while(T--){
		cin>>N;
		ostringstream oss;
		oss<<N;
		cout<<pallin(oss.str())<<endl;
	}
	return 0;
}