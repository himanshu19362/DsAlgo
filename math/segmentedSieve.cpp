#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int N = 1e5;
int sieve[N+1] = {0};
vector<int> primes;


/*
	We have to print all prime nos between m and n (both inclusive).	
	1 <= m,n <= 1e9
	n-m<=100000

	We find all primes till sqrt(n) and then apply normal sieve in the new array.
*/

void primeSieve(){
	for(int i = 2 ; i <= N ; i++){
		if(sieve[i] == 0){
			primes.push_back(i);
			for(int j = i*i ; j <= N ; j += i){
				sieve[j] = 1;
			}
		}
	}
}

int32_t main(){

	primeSieve();
	int t;
	cin>>t;

	while(t--){
		int m , n;	
		cin>>m>>n;
		
		int segment[n-m+1] = {0};	//0 in this array represents prime no.
		
		for(auto p:primes){
			if(p*p > n)		break;
			
			int start = (m/p)*p;
			
			if(p>=m and p<=n)	start = 2*p;	//If p is greater than start of range , then start of 2*p.

			for(int i = start ; i <= n ; i += p){
				if(i < m)	continue;
				segment[i-m] = 1;
			}
		}

		for(int i = 0 ; i < n-m+1 ; i++){
			if(segment[i] == 0)	cout<<i+m<<" ";
		}
		cout<<endl;
	}
	return 0;		
}