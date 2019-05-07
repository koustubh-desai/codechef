/*
	N,K <= 10^7

*/
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;
std::vector<int> primes;
void checkIfPrime(int newPrime){
	int s = primes.size();
	int check_till = sqrt((double)newPrime);
	bool is_prime = true;
	for(int i=0; i<s && primes[i]<=check_till;i++){
		if(newPrime%primes[i]==0){
			is_prime = false;
			break;
		}
	}
	if(is_prime){
		primes.push_back(newPrime);
	}
}
void populatePrimes(int count){
	//Populate primes with 10 more  
	if(count >= 3) return;
	int len = primes.size();
	int last = primes[len-1];
	checkIfPrime(last + 2);
	checkIfPrime(last + 4);
	populatePrimes(count+1);

}
int leastPrime(int a, int b, int c, int i){
	//i indicates the index of primes to be now considered
	if(a==2) return 2;
	if (i>= primes.size()); populatePrimes(0);
	
	if(primes[i] > c) return a;
	if(a%primes[i] == 0 && b%primes[i] !=0 ) return primes[i];
	return leastPrime(a, b ,c, i+1);
	//if a%p = 0 and p is prime return p
}
int main(void) 
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int T,N,min=1000000000;
	primes.push_back(2);primes.push_back(3);primes.push_back(5);
	vector<int> arr;
	cin>>T;
	while(T--){
		cin>>N;
		int temp = N/2+1;
		int max_check = sqrt((double)temp);
		cout<<leastPrime(temp, N-temp ,max_check, 0)<<endl;
	}
}
