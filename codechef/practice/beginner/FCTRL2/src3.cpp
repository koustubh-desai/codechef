/*
	N,K <= 10^7

*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
//#include <chrono>
using namespace std;
//using namespace std::chrono;
void Bucketsort(int *source, int numbers);
void swap(int *a, int *b);
string GetFactorial(int a);
string MultiplyBigInts(int a, string b);
string factorial[101];
int CharToInt(char c);
char IntToChar(int i);
int main(void) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int N,temp;
	string fact;
	int arr[101],sorted[101];
	//auto start = high_resolution_clock::now();
	cin>>N;
	temp = 0;
	/*Collect the numbers in array arr*/
	while(temp<N){
		cin>>arr[temp];
		sorted[temp]=arr[temp];
		++temp;
	}
	//Sort numbers in arr in different array sorted
	Bucketsort(sorted,N);
	//Iterate in descending order
	for(temp = 0; temp < N; temp++){
	//Calculate factorial function and store result in factorial array
		fact = GetFactorial(sorted[temp]);
		factorial[sorted[temp]] = fact;
	}
	// auto stop = high_resolution_clock::now();
	// auto duration = duration_cast<microseconds>(stop - start);

	//For output iterate through arr and output the result as factorial[arr[temp]]
	for(temp = 0; temp < N; temp++){
		cout<<"\n"<<factorial[arr[temp]];
	}

	//  cout<<" \n Time taken = "<<duration.count()<<" microseconds ";
	return 0;

}
string GetFactorial(int a){
	
	if(a <=1) return "1";
	if(factorial[a].empty()) {
		factorial[a] = MultiplyBigInts(a,GetFactorial(a-1));
	} 
	return factorial[a];
}
string MultiplyBigInts(int a, string b){
	int fcval=0,carry=0,pos;
	string result;
	ostringstream os1,oss;
	oss<<a;
	string num1 = oss.str();
	string num2 = b;
	reverse(num1.begin(),num1.end());
	reverse(num2.begin(),num2.end());
	//cout<<"\n for "<<num1<<" and "<<num2;
	for(int i=0;i<num1.length();i++){
		for(int j=0;j<num2.length();j++){
			pos = i+j;
			fcval += (num1[i]-'0') * (num2[j]-'0');
			//cout<<"\ni="<<i<<" j="<<j<<" pos="<<pos;
			if(pos>=result.length()){
				//cout<<"\n in if";
				carry = fcval/10; 
				fcval = fcval%10;
				//cout<<"\n  fcval="<<fcval<<" carry="<<carry;
				os1<<fcval;
				result.append(os1.str());
				os1.seekp(0);
				fcval = carry;
			}
			else{
				//cout<<"\n in else";
				fcval += (result[pos] - '0');
				carry = fcval/10;
				fcval = fcval%10;
				result[pos]=fcval + '0';
				while(carry>0 && ++pos<result.length()){
					cout<<"\n in while";
					fcval = result[pos] - '0';
					fcval += carry;
					carry = fcval/10;
					fcval = fcval%10;
					result[pos]=fcval + '0';
				}
			}
		}
		if(carry>0){
			os1<<carry;
			result.append(os1.str());
			os1.seekp(0);
		}
	}
	reverse(result.begin(),result.end());
	return result;
}
int CharToInt(char c){
	return c-'0';
}
char IntToChar(int i){
	return char((int)i - (int)48);
}
void Bucketsort(int *source, int numbers){
	int i,j;
	for(i=0;i<numbers;i++){
		for(j=i+1;j<numbers;j++){
			if(source[i] < source[j]){
				swap(source+i,source+j);
			}
		}
	}
}
void swap(int *a, int *b){
	*a += *b;
	*b = *a-*b;
	*a -= *b;
}
