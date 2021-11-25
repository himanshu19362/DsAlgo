#include <bits/stdc++.h>
using namespace std;
#define int long long int

/*
	It is used to find solution to the equation ax + by = c.
	The problem will be solved using extended euclid algorithm.
	
	let gcd(a,b) = g
	then a = k1*g and b = k2*g

	k1*g x + k2*g y = c
	k1 x + k2 y = c/g

	Now , c%g == 0 is neccessary for solution to exist bcoz LHS is an integral value , so RHS should be an integer.
	
	So , we can say that ax + by = kg. ...(1)

	Let x1 , y1 be solution to 
	ax + by = g (Can be found using extended euclid algo)
	Then ,

	a (k*x) + b (k*y) = k*g

	So , x = kx1 and y = ky1 where k = c/gcd(a,b)
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


vector<int> diophantine(int a , int b , int c){
	vector<int> result = extendedEuclid(a , b);
	if(c%result[2] == 0){
		int k = c/result[2];
		return {k*result[0] , k*result[1]};
	}
	return {};
}

int32_t main(){
	int a,b,c;
	cin>>a>>b>>c;

	vector<int> result = diophantine(a , b , c);

	if(result.size() == 0){
		cout<<"Solution doesn't exist"<<endl;
	}
	else{
		cout<<"x :"<<result[0]<<" y: "<<result[1]<<endl;
	}

	return 0;
	
}