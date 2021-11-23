#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1000000;


/*
	The inner loop will start from i*i and not from 2*i.
	
	The reason is all composite no's < i*i will be marked bcoz all these 
	composite no's will have divisor on left/less of/than i as any composite no has atleast 
	one factor less than equal to sqrt() of it.
*/

void primeSieve(vector<int> &sieve){
	sieve[0] = sieve[1] = 0;
	for(int i = 2 ; i <= N ; i++){
		if(sieve[i] == 1){
			for(int j = i*i ; j <= N ; j += i){
				sieve[j] = 0;
			}
		}
	}
}


int32_t main(){

	vector<int> sieve(N+1 , 1);		//true if prime.
	primeSieve(sieve);

	//Print prime nos between 2-100
	for(int i = 2 ; i <= 100 ; i++){
		if(sieve[i])	cout<<i<<" ";
	}
	cout<<endl;

	return 0;
		
}