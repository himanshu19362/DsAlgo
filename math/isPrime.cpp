#include <bits/stdc++.h>
using namespace std;
#define int long long int

/*
	We have to run our loop only till sqrt(n)
	Divisors always exist in pairs.

	sqrt(n) * sqrt(n) = n
	If one of the divisors is increased , then the other divisor has to be decreased so that their product is same.
	That's why running the loop till sqrt(n) works.
*/

bool isPrime(int n){		//O(sqrt(n))
	for(int i = 2 ; i*i <= n ; i++){
		if(n%i == 0)	return false;
	}
	return true;
}

int32_t main(){
	int n;
	cin>>n;

	cout<<isPrime(n)<<endl;
	return 0;
}