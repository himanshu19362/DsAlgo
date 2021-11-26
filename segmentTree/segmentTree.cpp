#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct SegmentTree{
	vector<int> segment;
	int n;
	
	void init(int n){
		this->n = n;
		segment.resize(4*n , 0);
	}

	void build(int start , int end , int node , vector<int> &v){
		if(start == end){
			segment[node] = v[start];
			return;
		}
		int mid = (start+end)/2;

		//Left Subtree start ... mid
		build(start , mid , 2*node + 1 , v);

		//Right Subtree mid+1 ... end
		build(mid+1 , end , 2*node + 2 , v);

		segment[node] = segment[2*node + 1] + segment[2*node + 2];
	}

	void build(vector<int> &v){			//Call this from main
		build(0LL , n-1 , 0 , v);
	}

	int query(int start , int end , int node , int l , int r){
		if(l > end or r < start)	return 0;
		if(start >= l and end <= r)	return segment[node];

		int mid = (start + end)/2;

		int query1 = query(start , mid , 2*node + 1 , l , r);
		int query2 = query(mid+1 , end , 2*node + 2 , l , r);
		return  query1 + query2;
	}

	int query(int l , int r){		//Call this from main
		return query(0 , n-1 , 0 , l , r);
	}

	void update(int start , int end , int node , int index , int value){
		if(start == end){
			segment[node] = value;
			return;
		}

		int mid = (start+end)/2;

		if(index <= mid){
			update(start , mid , 2*node + 1 , index , value);
		}
		else{
			update(mid+1 , end , 2*node + 2 , index , value);
		}

		segment[node] = segment[2*node + 1] + segment[2*node + 2];
	}


	void update(int index , int value){
		update(0 , n-1 , 0 , index , value);
	}

};



int32_t main(){

	vector<int> v = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};
	
	SegmentTree tree;
	tree.init(v.size());
	tree.build(v);

	cout<<tree.query(0,4)<<endl;
	cout<<tree.query(4,4)<<endl;
	
	cout<<tree.query(2,6)<<endl;

	tree.update(3 , 6);
	cout<<tree.query(2,6)<<endl;


	return 0;		
}