#include <bits/stdc++.h>
#define MOD 1000000000
#define ll long long
#define MAX 100000
using namespace std;

struct node{

  int data;
  node *left;
  node *right;
};

node* create_Node(int n){

  node *new_node = new node;
  new_node->data = n;
  new_node->left = NULL;
  new_node->right = NULL;

}

node* createBST(node *root, int num){

  node *new_node = create_Node(num);

  if(root == NULL){

    root = new_node;
    
 }

  else if(num < root->data){

    root->left = createBST(root->left, num);
  
  }
  else if(num > root->data){

    root->right = createBST(root->right, num);
  
  }

  return root;

}

void pre_order(node *root){

  if(root == NULL) return;

  cout << root->data <<" ";

  pre_order(root->left);

  pre_order(root->right);

}

void in_order(node *root){

  if(root == NULL) return;

  in_root(root->left);

  cout << root->data <<" ";

  in_root(root->right);

}

void post_order(node *root){

  if(root == NULL) return;

  post_order(root->left);

  post_order(root->right);

  cout << root->data <<" ";


}

int main() {

  int num;

  node *root = NULL;

  cin >> num;

  while(num){

    root = createBST(root, num);

  }

  pre_order(root);

  in_order(root);

  return 0;

}
