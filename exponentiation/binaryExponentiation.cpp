#include <bits/stdc++.h>
using namespace std;
#define int long long int

int powm(int a , int b , int mod){	
	//Eg : 2^11 = 2^1011 = 2^8 * 2^2 * 2^1

	int ans = 1;
	while(b){
		if(b&1)	ans = ans*a , ans = ans%mod;
		a = a*a;
		a = a%mod;
		b = b>>1;
	}
	return ans;
}

int multiply(int a , int b , int mod){
	// we have to find (a*b)%mod.  1 <= a,b,mod <= 10^15
	// if a,b = 10^15 - 1 and mod = 10^15 then overflow possible.	
	// So , we apply binary multiplication

	//Eg: 2*11 = 2*(1011) = 2*8 + 2*2 + 2*1

	int ans = 0;
	while(b){
		if(b&1)	ans += a , ans = ans%mod;
		a = 2*a;
		a = a%mod;
		b = b>>1;
	}
	return ans;
}


int32_t main(){
	cout<<powm(2 , 200 , 1e9 + 7)<<endl;
	cout<<multiply(20 , 20 , 1e9 + 7)<<endl;
	return 0;
		
}