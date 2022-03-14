#include <bits/stdc++.h>
using namespace std;

struct Node{
	Node* links[26];
	bool flag = false;

	bool containsKey(char c){
		return links[c-'a']!=NULL;
	}

	void addKey(char c){
		links[c-'a'] = new Node();
	}

	Node* getNode(char c){
		return links[c-'a'];
	}



};

class Trie{
private:
	Node* root;

public:
	Trie(){
		root = new Node();
	}

	void insert(string s){
		Node* node = root;

		for(char &c:s){
			if(!node->containsKey(c))	node->addKey(c);
			node = node->getNode(c);
		}

		node->flag = true;
	}

	bool search(string s){
		Node* node = root;
		for(char &c:s){
			if(!node->containsKey(c))	return false;
			node = node->getNode(c);
		}
		return node->flag;
	}

	bool containsPrefix(string s){
		Node* node = root;
		for(char &c:s){
			if(!node->containsKey(c))	return false;
			node = node->getNode(c);
		}
		return true;
	}
};



int main(){

	Trie t;
	t.insert("apple");
	t.insert("bat");
	t.insert("apps");

	cout<<t.search("apple")<<endl;
	cout<<t.search("app")<<endl;
	cout<<t.containsPrefix("app")<<endl;
	cout<<t.containsPrefix("bat")<<endl;


	return 0;

}