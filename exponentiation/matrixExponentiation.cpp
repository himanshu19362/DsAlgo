#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9 + 7;

//Matrix Exponentiation is basically binary exponentiation on matrices.
/*
T*f(n) = f(n+1)
T*f(2) = f(3)
T*f(3) = f(4)
T*f(4) = f(5)
-
T(T*f(3)) = f(5)
T*T*T*f(2) = f(5)

T^(n-2) * f(2) = f(n)
*/

const int size = 2;

struct Mat{
	int mat[size][size];

	Mat(){
		memset(mat , 0 , sizeof(mat));		
	}

	void identity(){
		for(int i = 0 ; i < size ; i++){
			mat[i][i] = 1;
		}
	}

	Mat operator* (Mat b){
		Mat mul;
		for(int i = 0 ; i < size ; i++){
			for(int j = 0 ; j < size ; j++){
				for(int k = 0 ; k < size ; k++){
					mul.mat[i][j] += (mat[i][k]*b.mat[k][j]) ;
					mul.mat[i][j] %= mod;
				}
			}
		}
		return mul;
	}
};

//f1 = 1 , f2 = 1 , f3 = 2 , f4 = 3 , f5 = 5 , f6 = 8.
int fib(int n){
	if(n<=2)	return 1;
	
	// n-=2;
	n = n-2;
	Mat ans;
	ans.identity();

	Mat T;
	T.mat[0][0] = T.mat[0][1] = T.mat[1][0] = 1;
	

	while(n){
		if(n & 1)		ans = ans*T;
		T = T*T;
		n = n>>1;
	}
	return (ans.mat[0][0] + ans.mat[0][1])%mod;
}



int32_t main(){

	int n = 10;
	cout<<fib(n)<<endl;		
	return 0;
}