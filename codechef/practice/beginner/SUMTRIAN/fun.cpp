#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int T;
vector<string> tra;
int max(int a, int b){
	return a>b?a:b;
}
int path(int sum, int x, int y){
	if(x>=T) return sum;
	if(y>=tra[x].length()) return sum;
	sum += tra[x][y] - '0';
	return max(path(sum,x+1,y),path(sum,x+1,y+1));
}
int main(){
	int i=0,j=0,N;
	cin>>T;
	for(i=0;i<T;i++){
		string bij;
		cin>>bij;
		tra.push_back(bij);
	}
	N=path(0,0,0);
	cout<<" best is "<<N<<endl;
	return 0;
}