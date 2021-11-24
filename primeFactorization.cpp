#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1000000;


void primeSieve(vector<int> &sieve){
	for(int i = 2 ; i <= N ; i++){
		if(sieve[i] == 1){	
			sieve[i] = i;
			for(int j = i*i ; j <= N ; j += i){
				if(sieve[j] == 1){
					sieve[j] = i;
				}
			}
		}
	}	
}

void primeFactorization(int n){		//O(sqrt(n))
	for(int i = 2 ; i*i <= n ; i++){
		int cnt = 0;
		while(n%i == 0){
			cnt++;
			n /= i;
		}
		if(cnt>0)	cout<<i<<"^"<<cnt<<endl;
	}
	if(n > 1)	cout<<n<<"^"<<1<<endl;
}


//Building sieve takes O(n(log(log(n)))
//After that each query takes log(n) time to print prime factorization.
void primeFactorizationSieve(int n){	
	
	vector<int> sieve(N+1 , 1);
	primeSieve(sieve);
	while(n!=1){
		cout<<sieve[n]<<" ";
		n /= sieve[n];
	}
}



int32_t main(){
	int n;
	cin>>n;

	primeFactorization(n);
	primeFactorizationSieve(n);
	return 0;
}