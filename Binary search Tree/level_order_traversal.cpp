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

void level_order(node *root){

  queue<node *>q[MAX];

  q.push(root);

  while(!q.empty()){

    root = q.front();
    cout << q.front() << " ";
    q.pop();

    if(root->left != NULL) q.push(root->left);
    if(root->right != NULL) q.push(root->right);

  }


}

int main() {

  int num;

  node *root = NULL;

  cin >> num;

  while(num){

    root = createBST(root, num);

  }

  level_order(root);

  return 0;

}