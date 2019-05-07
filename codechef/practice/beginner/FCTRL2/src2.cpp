/*
	N,K <= 10^7

*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
//#include <chrono>
using namespace std;
//using namespace std::chrono;
void Bucketsort(int *source, int numbers);
void swap(int *a, int *b);
int GetFactorial(int a);
int factorial[101];
int main(void) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int N,temp,fact;
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
		cout<<"\n Factorial of jojo"<<arr[temp]<<" is "<<factorial[arr[temp]];
	}

	//  cout<<" \n Time taken = "<<duration.count()<<" microseconds ";
	return 0;

}
int GetFactorial(int a){
	if(a <=1) return 1;
	if(!factorial[a]) {factorial[a] = a*GetFactorial(a-1);}
	return factorial[a];
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
