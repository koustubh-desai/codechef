#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <tuple>
#include <bits/stdc++.h>
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep_inverse(i,a,b)  for(int i=a;i>=b;i--)
#define max(a,b) a>b?a:b
#define input(v) for(int i=0; i <9; i++) cin>>v[i]
#define output(v) for(int i=0; i <9; i++) cout<<v[i]<<" "
#define isPrimeNumber(s) (s==3 || s==5 || s==7 || s==11 || s==13 || s==17) 

using namespace std; 
vector<int> sorted = {1,2,3,4,5,6,7,8,9};
//vector<int> sorted = {7,3,2,4,1,5,6,8,9};
int calls = 0;
int limit = 100;
int getPos(char pos, int index){
	
	switch(pos){
		case 'l':
			switch(index){
				case 0: return -1;
				case 1: return 0;
				case 2: return 1;
				case 3: return -1;
				case 4: return 3;
				case 5: return 4;
				case 6: return -1;
				case 7: return 6;
				case 8: return 7;
				default: return -2;
			}
			break;
		case 't':
			switch(index){
				case 0: return -1;
				case 1: return -1;
				case 2: return -1;
				case 3: return 0;
				case 4: return 1;
				case 5: return 2;
				case 6: return 3;
				case 7: return 4;
				case 8: return 5;
				default: return -2;
			}
			break;
		case 'b':
			switch(index){
				case 0: return 3;
				case 1: return 4;
				case 2: return 5;
				case 3: return 6;
				case 4: return 7;
				case 5: return 8;
				case 6: return -1;
				case 7: return -1;
				case 8: return -1;
				default: return -2;
			}
			break;
		case 'r':
			switch(index){
				case 0: return 1;
				case 1: return 2;
				case 2: return -1;
				case 3: return 4;
				case 4: return 5;
				case 5: return -1;
				case 6: return 7;
				case 7: return 8;
				case 8: return -1;
				default: return -2;
			}
			break;
		default: return -2;
			
	}
	
}
bool isValid(int currentFrom, int currentTo, int prevTo, int prevFrom, vector<int> &v){
	if(currentTo <0 || currentFrom < 0) return false;
	if((currentFrom == prevFrom && currentTo==prevTo) || (currentFrom == prevTo && currentTo==prevFrom)) return false;
	if(!isPrimeNumber(v[currentFrom]+v[currentTo])) return false;
	if(v[currentFrom] == currentFrom+1) return false;
	if(v[currentTo] == currentTo+1) return false;
	return true;
}
void ssort(vector<int> v, int from, int to, int count, vector<int> &arr,int indexx,bool found){
	if(++calls>=limit) return;
	if(indexx%9){
		//cout<<" One cycle is over and found is "<<found<<endl;
		if(!found) {
			cout<<" GANJAAAAA returning"<<endl;
			return;
		}
		found = false;
	}
	int temp;
	int current = indexx%9;
	//swap values
	if(from >=0 && to >= 0 && from!=to){
		cout<<" For arr"<<endl;
		output(v);
		cout<<" swap pos from="<<from<<" swap pos to="<<to<<" val1="<<v[from]<<" val2="<<v[to]<<endl;
		temp = v[from];
		v[from] = v[to];
		v[to] = temp;
	}
	if(v == sorted) {
		cout<<"WOOOHOOOOO"<<count<<endl;
		cout<<" and size of arr is "<<arr.size()<<endl;
		arr.push_back(count);
		sort(arr.begin(), arr.end(),[](int a,int b){return a<b;}); 
		return;
	}
	rep(i,current,8){
	//rep_inverse(i,8,current){
		 //check left
		 temp = getPos('l',i);
		 if(isValid(i,temp,to,from,v)){
		 	found = true;
		 	ssort(v,i,temp,count+1,arr,i,found);
		 }
		 
		  //check right
		 temp = getPos('r',i);
		 if(isValid(i,temp,to,from,v)) {
		 	found = true;
		 	ssort(v,i,temp,count+1,arr,i,found);
		 }
		 
		  //check top
		 temp = getPos('t',i);
		 if(isValid(i,temp,to,from,v)) {
		 	found = true;
		 	ssort(v,i,temp,count+1,arr,i,found);
		 }
		 
		  //check bottom
		 temp = getPos('b',i);
		 if(isValid(i,temp,to,from,v)) {
		 	found = true;
		 	ssort(v,i,temp,count+1,arr,i,found);
		 }
	}
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	std::ifstream in("test.txt");
	std::streambuf*cinbuf = std::cin.rdbuf(); // save old buff
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to be in  .txt!
	std::string line;
	int N,T;
	
	cin>>T;
	while(T--){
		vector<int> count = {};
		vector<int> v(9);
		input(v);
		cout<<"GETTING STARTED"<<endl;
		ssort(v,-1,-1,0,count,0,false);
	}
	return 0;
}
