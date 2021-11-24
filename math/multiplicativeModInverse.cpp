#include <bits/stdc++.h>
using namespace std;
#define int long long int


/*
	ax = 1 mod m
	then x is multiplicative modulo inverse of a under m.
	For inverse to exist , gcd(a,m) = 1.

	ax + my = 1
	Taking % m both side

	ax%m = 1
	ax = 1 mod m
	So , basically we have to find value of x which will be mmi.
	So , this can be calculted using extended euclid algorithm.

*/

vector<int> extendedEuclid(int a , int b){
	if(b == 0){
		return {1 , 0 , a};
	}

	vector<int> subProblem = extendedEuclid(b , a%b);
	
	int newX = subProblem[0];
	int newY = subProblem[1];
	int gcd = subProblem[2];

	int x = newY;
	int y = newX - (a/b)*newY;

	return {x , y , gcd};
}

int modInverse(int a , int m){

	vector<int> result = extendedEuclid(a , m);

	if(result[2] !=1)	return -1;

	return (result[0]%m + m)%m;		// 1 <= x <= m-1
}

int32_t main(){

	int a,m;
	cin>>a>>m;
	cout<<modInverse(a , m)<<endl;

	return 0;	
}