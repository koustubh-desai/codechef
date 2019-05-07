#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#define UPDATE_DIGIT carry = fcval/10; fcval = fcval%10; os1<<fcval; result[pos]=os1.str()[0]; os1.seekp(0);

void swap(int *a, int *b){
	*a += *b;*b = *a-*b;*a -= *b;
}
void Bucketsort(int *source, int numbers){
	int i,j;
	for(i=0;i<numbers;i++)for(j=i+1;j<numbers;j++) if(source[i] < source[j]) swap(source+i,source+j);
}
string factorial[101];
string MultiplyBigInts(int a, string b){
	int fcval=0,carry=0,pos;
	ostringstream os1,oss;
	oss<<a;
	string result,num1 = oss.str(),num2=b;
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());
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
string GetFactorial(int a){	
	if(a <=1) return "1";
	if(factorial[a].empty()) factorial[a] = MultiplyBigInts(a,GetFactorial(a-1));
	return factorial[a];
}
int main(void) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int N,temp,arr[101],sorted[101];
	string fact;
	cin>>N;
	temp = 0;
	while(temp<N){
		cin>>arr[temp];
		sorted[temp]=arr[temp];
		++temp;
	}
	Bucketsort(sorted,N);
	for(temp = 0; temp < N; temp++){
		factorial[sorted[temp]] = GetFactorial(sorted[temp]);
	}
	for(temp = 0; temp < N; temp++){
		cout<<"\n"<<factorial[arr[temp]];
	}
	return 0;

}