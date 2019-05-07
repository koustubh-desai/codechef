/*
	N,K <= 10^7

*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
void Bucketsort(int *source, int numbers);
void swap(int *a, int *b);
int GetFactorial(int a);
int main(void) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int N,temp,fact;
	int arr[101],sorted[101],factorial[101];
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
	
	//For output iterate through arr and output the result as factorial[arr[temp]]
	for(temp = 0; temp < N; temp++){
		cout<<"\n Factorial of"<<arr[temp]<<" is "<<factorial[arr[temp]];
	}
}
int GetFactorial(int a){
	if(a <=1) return 1;
	return a*GetFactorial(a-1);
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
	cout<<"I am in bucket sort";
}
void swap(int *a, int *b){
	*a += *b;
	*b = *a-*b;
	*a -= *b;
}
