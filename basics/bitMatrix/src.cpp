#include <iostream>
#include <sstream>
#include <vector>

#include <fstream>
#include <string>
using namespace std;
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define max(a,b) a>b?a:b
int a[10][10];
int rn, maxNo = 0;
int right(int i, int j, int sum){
	if(sum == 0 && j-1>=0 && a[i][j-1] == 1) return 0; // First 1 in sequence. Check if no previous 1
	if(i>= rn || j>= rn || a[i][j] == 0) return sum;
	return right(i,j+1,sum+a[i][j]);
}
int down(int i, int j, int sum){
	if(sum == 0 && i-1>=0 && a[i-1][j] == 1) return 0; // First 1 in sequence. Check if no previous 1
	if(i>= rn || j>= rn || a[i][j] == 0) return sum;
	return down(i+1,j,sum+a[i][j]);
}
int rightDiagonal(int i, int j, int sum){
	if(sum == 0 && i-1>=0 && j-1>=0 && a[i-1][j-1] == 1) return 0; // First 1 in sequence. Check if no previous 1
	if(i>= rn || j>= rn || a[i][j] == 0) return sum;
	return rightDiagonal(i+1,j+1,sum+a[i][j]);
}
int leftDiagonal(int i, int j, int sum){
	if(sum == 0 && i-1>=0 && j+1<rn && a[i-1][j+1] == 1) return 0; // First 1 in sequence. Check if no previous 1
	if(i<0 || j<0 || i>= rn || j>= rn || a[i][j] == 0) return sum;
	return leftDiagonal(i+1,j-1,sum+a[i][j]);
}
int main(){
	std::ifstream in("test.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    std::string line;
    int i, j;
    
    cin>>rn;
    rep(i,0,rn){
    	rep(j,0,rn){
    		cin>>a[i][j];
    	}
    }
    rep(i,0,rn){
    	rep(j,0,rn){
    		maxNo = max(maxNo,right(i,j,0));
    		maxNo = max(maxNo,down(i,j,0));
    		maxNo = max(maxNo,rightDiagonal(i,j,0));
    		maxNo = max(maxNo,leftDiagonal(i,j,0));
    	}
    }
    cout<<"max found is "<<maxNo;
    
    /*cout<<" got "<<i;
    getline(cin,line);
    cout<<" line i got is "<<line;*/
    /*while(std::getline(std::cin, line))  //input from the file in.txt
    {
        std::cout << line << "\n";   //output to the file out.txt
    }*/
	/*int i=0,j=0,N;
	int a=1,b=2,c=3,d=4;
	string temp;
	cin>>T;
	while(T--){
		cin>>temp;
		row.push_back(temp);

	}*/
}