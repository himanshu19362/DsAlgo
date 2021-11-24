#include <bits/stdc++.h>
using namespace std;
#define int long long int

/*
	In long division/euclid algo , remainder becomes new divisor and old divisor becomes new divident .
	gcd(a , b)	a:divident  b:divisor
*/


int gcd(int a , int b){
	if(b == 0)	return a;
	return gcd(b , a%b);
}

int32_t main(){
	int a,b;
	cin>>a>>b;

	cout<<gcd(a , b)<<endl;
	return 0;	
}