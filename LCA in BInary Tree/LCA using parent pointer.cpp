// Time Complexity - O(h)
//	Space Complexity - O(1)

#include<bits/stdc++.h>
#define ll long long int
#define llu unsigned long long int
#define db double
#define bsa(v,n,a) binary_search(v,v+n,a)
#define bsv(v,a) binary_search(v.begin(),v.end(),a)
#define PI 3.1415926535897932
#define XOR(a, b) ((a|b)&(~a|~b))
using namespace std;

struct Node{
	
	Node *left, *right, *parent;
	int value;
};

Node* NewNode(int key){

	Node *New_Node = new Node;
	New_Node->value = key;
	New_Node->left = New_Node->right = New_Node->parent = NULL;
	return New_Node;	
}

Node* insert(Node *root, int value){

	if(root == NULL) return(NewNode(value));
	if(value < root->value) {root->left = insert(root->left, value); root->left->parent = root;} 
	else {root->right = insert(root->right, value); root->right->parent = root;}
	return root;
}

int depth(Node *n){

	int d = -1;
	while(n){

		++d;
		n = n->parent;
	}
	return d;
}

Node *findLCA(Node *n1, Node *n2){

	int d1 = depth(n1), d2 = depth(n2), diff = d1 - d2;
	if(diff < 0){

		swap(n1, n2);
		diff = -diff;
	}
	while(diff--){n1 = n1->parent;}
	
	// Now n1 and n2 are at the same level
	while(n1 && n2){

		if(n1 == n2) return n1;
		n1 = n1->parent;
		n2 = n2->parent;
	}
	return NULL;
}


int main(){

	//ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	   
	Node *root = NULL;
	root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
 
    Node *n1 = root->left->right->left;
    Node *n2 = root->right;

	Node *lca = findLCA(n1, n2);
	if(lca == NULL) cout <<"LCA does'nt exist's";
	else cout <<"LCA of " << n1->value <<" and " << n2->value <<" is "<<lca->value <<"\n";

	return 0;
}