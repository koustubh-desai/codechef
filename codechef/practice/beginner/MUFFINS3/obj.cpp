#include <iostream>
#include <sstream>
#include <conio.h>
using namespace std;

class Student{
public:
	int id;
	Student(){

	}
	Student(int x){
		id = x;
	}
	~Student(){
		cout<<" in destructor of "<<id;
	}
	void roll(){
		cout<<"In student"<<id<<endl;
	}
};

int main(void){
	Student s1(20);
	cout<<"heyo";
	/*s1.roll();
	int i = 10,j;
	ostringstream oss;
	while(--i){
		cin>>j;
		oss<<j;
		cout<<oss.str();
	}
	char input = getchar();
	cout<<"I got ---> "<<input;
	if(kbhit()!=0){
		cout<<"\n GJALA "<<getch();
	}*/
		char ch;
		ostringstream oss;
		string s;
		while(1){
			ch=getch();
			oss<<ch;
			s.append(oss.str());
			oss.seekp(0);
			if(ch == '~') { break; }
		}
		cout<<" I got "<<s;
	return 0;
}