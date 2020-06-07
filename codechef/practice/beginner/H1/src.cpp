#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <tuple>
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define max(a,b) a>b?a:b
#define take(arr) for(int i=0; i<3; i++) for(int j=0; j<3; j++) cin>>arr[i][j];
#define out(arr) for(int i=0; i<3; i++) {for(int j=0; j<3; j++) cout<<arr[i][j]<<" "; cout<<endl;}

#define in2(arr) cin>>arr[0][0]>>arr[0][1]>>arr[0][2]>>arr[1][0]>>arr[1][1]>>arr[1][2]>>arr[2][0]>>arr[2][1]>>arr[2][2];
#define out2(arr) cout<<arr[0][0]<<arr[0][1]<<arr[0][2]<<"\n"<<arr[1][0]<<arr[1][1]<<arr[1][2]<<"\n"<<arr[2][0]<<arr[2][1]<<arr[2][2]<<endl;
#define twod vector<vector <int> >
//is array sorted
#define issolved(a) (a[0][0] == 1) && (a[0][1] == 2) && (a[0][2] == 3) && (a[1][0] == 4) && (a[1][1] == 5) && (a[1][2] == 6) && (a[2][0] == 7) && (a[2][1] == 8) && (a[2][2] == 9);
#define isvalid(i,j,k,l) (i>=0) && (i<=2) && (j>=0) && (j<=2) && (k>=0) && (k<=2) &&(l>=0) && (l<=2) && ((i==k-1 && j==l) || (i==k+1 && j==l) || (i==k && j==l-1) || (i==k-1 && j==l+1))
#define isprime(n) n==2 || n==3 || n==5 || n==7 || n==11 || n==13 || n==17
#define isend(i,j) (i==2 && j==2)
using namespace std;
int ssort(twod arr, int i, int j, int m, int n, int count, bool firstTime){
	if issolved(arr) return count;
	if(firstTime){
		cout<<"FIRSTOS"<<issolved(arr);
		vector <int> counts;
		firstTime = false;
		for(i = 0; i<=2 i++) for(j = 0; j<=2; j++) {
			counts.push_back(ssort(arr,i,j,i-1,j,0,false));
			counts.push_back(ssort(arr,i,j,i+1,j,0,false));
			counts.push_back(ssort(arr,i,j,i,j-1,0,false));
			counts.push_back(ssort(arr,i,j,i,j+1,0,false));
		}
		
		i=0; j=0; m = 0; n = 1;
	}
	else{
		if(isvalid(i,j,m,n) && isprime(arr[i][j] + arr[m][n])){
			//swap
			int temp = arr[i][j];
			arr[i][j] = arr[m][n];
			arr[m][n] = temp;
			//increment count
			++count;
			//check ifsolved
			//check ifend
			
		}
	}
	return count;
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	std::ifstream in("test.txt");
	std::streambuf*cinbuf = std::cin.rdbuf(); // save old buff
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to be in  .txt!
	std::string line;
	int N,T,temp;
	char Instr;
	cin>>T;
	while(T--){
		twod arr =  {{0,0,0},{0,0,0},{0,0,0}};
		take(arr);
		//cout<<ssort(arr,-1,-1,-1,-1,-1,true)<<endl;
		ssort(arr,-1,-1,-1,-1,-1,true);
	}
	return 0;
}
