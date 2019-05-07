#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
string MultiplyBigInts(int a, string b){
	int fcval=0,carry=0,pos;
	ostringstream os1,oss;
	string result="",num1,num2=b;
	oss<<a;
	num1 = oss.str();
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());
	cout<<"\n for "<<num1<<" and "<<num2;
	for(int i=0;i<num1.length();i++){
		for(int j=0;j<num2.length();j++){
			pos = i+j;
			if(pos >= result.length()){
				fcval = (num1[i] - '0') * (num2[j] - '0') + carry;
				carry = fcval/10;
				fcval %= 10;
				os1<<fcval;
				result.append(os1.str());
				os1.seekp(0);
			}
			else{
				fcval = (num1[i] - '0') * (num2[j] - '0') + carry + (result[pos] - '0');
				carry = fcval/10;
				fcval %= 10;
				os1<<fcval;
				result[pos] = os1.str()[0];
				os1.seekp(0);
			}
		}
		if(carry > 0){
			os1<<carry;
			result.append(os1.str());
			os1.seekp(0);
			carry = 0;
		}
	}
	reverse(result.begin(),result.end());
	return result;
} 

int main(void) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	string n="15511210043330985984000000",result;
	int n2=26;
	result = MultiplyBigInts(n2,n);
	cout<<"Result is "<<result; 
	return 0;

}