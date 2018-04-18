#include<bits/stdc++.h>
using namespace std;

struct Node{
	
	Node *left, *right;
	int key;
};

Node* NewNode(int v){

	Node *new_node = new Node;
	new_node->key = v;
	new_node->left = new_node->right = NULL;
	return new_node;
}

Node* findLCAUtil(Node *root, int n1, int n2, bool &v1, bool &v2){

	if(root == NULL) return NULL;
	if(root->key == n1){

		v1 = true;
		return root;
	}
	else if(root->key == n2){

		v2 = true;
		return root;
	}

	Node *lca1 = findLCAUtil(root->left, n1, n2, v1, v2);
	Node *lca2 = findLCAUtil(root->right, n1, n2, v1, v2);

	if(lca1 && lca2) return root;

	return (lca1 != NULL ? lca1 : lca2);

}

bool find(Node *lca, int v){

	if(lca == NULL) return false;
	if(lca->key == v || find(lca->left, v) || find(lca->right, v)) return true;
	return false;
}

Node* findLCA(Node *root, int n1, int n2){

	bool v1 = false, v2 = false;
	Node *lca = findLCAUtil(root, n1, n2, v1, v2);
	
	if(v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1)) return lca;
	return NULL;
}

int main(){

//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	Node *root = NewNode(1);
	root->left = NewNode(2);
	root->right = NewNode(3);
	root->left->left = NewNode(4);
	root->left->right = NewNode(5);
	root->right->left = NewNode(6);
	root->right->right = NewNode(7);

	Node *lca = findLCA(root, 2, 3);
	if(lca != NULL) cout <<"LCA is " << lca->key <<"\n";
	else cout <<"LCA not found\n";

	lca = findLCA(root, 2, 4);
	if(lca != NULL) cout <<"LCA is " << lca->key <<"\n";
	else cout <<"LCA not found\n";

return 0;	
}