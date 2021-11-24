#include <bits/stdc++.h>
using namespace std;
#define int long long int

/*
	Given an equation ax + by = gcd(a , b)
	We know gcd(a , b) = gcd(b , a%b)
	ax + by = bx1 + (a-[a/b]*b) y1

	Comparing a and b both side .
	x = y1 and y = x1+[a/b]*y1
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

int32_t main(){
	int a,b;
	cin>>a>>b;

	vector<int> ans = extendedEuclid(a , b);
	cout<<"x : " <<ans[0]<<"\ny : "<<ans[1]<<"\ngcd : "<<ans[2]<<endl;

	return 0;

}
//2x + 3y = 1