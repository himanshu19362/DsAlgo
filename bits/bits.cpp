#include <bits/stdc++.h>
using namespace std;

//Bits follow 0 based indexing from right

int get_ith_bit(int n , int i){		
	int mask = (1 << i);
	if(n&mask)	return 1;
	return 0;
}

void clear_ith_bit(int &n , int i){
	int mask = ~(1<<i);
	n = n&mask;
}

void set_ith_bit(int &n , int i){
	int mask = (1<<i);
	n = n | mask;
}

void update_ith_bit(int &n , int i , int v){
	clear_ith_bit(n , i);
	int mask = (v<<i);
	n = n | mask;
}

void clearLastBits(int &n , int i){	//i:1-31
	int mask = ((~0)<<i);
	n = n&mask;
}

void clear_bits_in_range(int &n , int i , int j){
	int a = ((-1)<<(j+1));
	int b = ~((-1)<<i);

	int mask = a | b;

	n = n & mask;	
}

int count_set_bits(int n){
	int count = 0;
	while(n){
		count++;
		n = (n&(n-1));
	}
	return count;
}

int convertToBinary(int n){
	int ans = 0;
	int p = 1;	//10^0

	while(n){
		int digit = n&1;
		ans += digit*p;
		p *= 10;
		n = n>>1;
	}
	return ans;
}

int main(){
	int n = 5;

	//Get ith bit
	cout<<get_ith_bit(n , 2)<<endl;

	//Clear ith bit.
	n = 13;
	clear_ith_bit(n , 2);
	cout<<n<<endl;

	//Set ith bit
	n = 5;
	set_ith_bit(n , 1);
	cout<<n<<endl;


	//Update ith bit
	n = 13;
	update_ith_bit(n , 1 , 1);

	cout<<n<<endl;

	//Clear last i bits where i = 1:31
	n = 15;
	clearLastBits(n , 2);
	cout<<n<<endl;

	//Clear bits in range.
	n = 3758;	
	clear_bits_in_range(n , 1 , 6);	
	cout<<n<<endl;

	//Count set bits
	n = 15;
	cout<<count_set_bits(n)<<endl;

	//Covert int to binary form using int.

	n = 15;
	cout<<convertToBinary(n)<<endl;


	return 0;
		
}



