#include <iostream>
#include <sstream>
#include <vector>

#include <fstream>
#include <string>

#define rep(i,a,b)  for(int i=a;i<b;i++)
#define max(a,b) a>b?a:b
#define changeInput std::ifstream in("test2.txt"); \
    std::streambuf *cinbuf = std::cin.rdbuf(); \
    std::cin.rdbuf(in.rdbuf()); \
    std::string line; 
#define changeOutput std::ifstream out("out.txt"); \
    std::streambuf *cinbuf = std::cout.rdbuf(); \
    std::cout.rdbuf(out.rdbuf()); \
    std::string line; 
using namespace std;
int main(){
    changeInput;
	int i,j;
    cin>>i;
    cout<<"I got "<<i;
    while(i--){
    	cin>>j;
    	cout<<"\n got "<<j;
    	if (cin.get() == '\n'){
    		cout<<"\n I got an enter key";
    	}
    }
    
    
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