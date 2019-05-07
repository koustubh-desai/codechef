#include <iostream>
#include <sstream>
#include <vector>

#include <fstream>
#include <string>
using namespace std;
int T;
vector<string> row;
int max(int a, int b, int c){
	return a>b?a:b;
}
int path(int sum, int x, int y){
	if(x>=T) return sum;
	if(y>=row[x].length()) return sum;
	if(row[x][y] == '0') return sum;
	sum += row[x][y] - '0';
	return max(path(sum,x+1,y),path(sum,x,y+1),path(sum,x+1,y+1));
}
int main(){
	std::ifstream in("test.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
    std::string line;
    int i;
    cin>>i;
    cout<<" got "<<i;
    getline(cin,line);
    cout<<" line i got is "<<line;
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