#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int T;
vector<string> row;
int max(int a, int b){
	return a>b?a:b;
}
int path(int sum, int x, int y){
	if(x>=T) return sum;
	if(y>=row[x].length()) return sum;
	sum += row[x][y] - '0';
	return max(path(sum,x+1,y),path(sum,x+1,y+1));
}
int main(){
	int i=0,j=0,N;
	string temp;
	cin>>T;
	while(T--){
		cin>>temp;
		row.push_back(temp);

	}
}