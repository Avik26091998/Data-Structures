// The complexity of creating a trie is O(W*L), 
// where W is the number of words, and L is an average length of the word: 
// you need to perform L lookups on the average for each of the W words in the set.


#include<bits/stdc++.h>
using namespace std;

struct node{

  int isword;
  node *child[26];

};

node *Newnode(){

  node* new_node = new node;
  new_node->isword = 0;
  for(int i = 0; i < 26; ++i) new_node->child[i] = NULL;
  return new_node;

}

node* addword(node *root, string s){

  node *temp = root;
  root = temp;

  for(int i = 0; i < s.length(); ++i){

      int ch = s[i] - 'a';
      if(temp->child[ch] == NULL) temp->child[ch] = Newnode();
      temp = temp->child[ch];
  }

  temp->isword = 1;

  return root;

}

int findword(node *root, string s){

  node *temp = root;

  for(int i = 0; i < s.length(); ++i){

    int ch = s[i] - 'a';
    if(temp->child[ch] == NULL) return 0;
    else temp = temp->child[ch];
  }

  if(temp->isword == 1) return 1;
  else return 0;
}

int isempty(node *root){

  for(int i = 0; i < 26; ++i){

    if(root->child[i] != NULL) return 0;
  }
  return 1;
}

void remove(node **root, string s, int index, int n){

  if(*root == NULL) return;
  if(index == n){

    if((*root)->isword == 1) (*root)->isword = 0;
    if(isempty(*root)) delete[] *root;
    return;
  }

  remove(&(*root)->child[s[index] - 'a'], s, index + 1, n);
  if(isempty(*root)) delete[] *root;

}


int main(){

  node *root = Newnode();
  root = addword(root, "avik");
  root = addword(root, "ava");
  root = addword(root, "pogba");
  root = addword(root, "avika");
  root = addword(root, "Lingard");


  findword(root, "avika") == 1 ? cout <<"avika exists\n" : cout <<"avika does'nt exists\n";
  findword(root, "avik") == 1 ? cout << "avik exists\n" : cout << "avik does'nt exists\n";
  findword(root, "ava") == 1 ? cout << "ava exists\n" : cout <<"ava does'nt exists\n";
  findword(root, "a") == 1 ? cout << "a exists\n" : cout <<"a does'nt exists\n";
  findword(root, "Lingard") == 1 ? cout << "Lingard exists\n" : cout <<"Lingard does'nt exists\n";  

  remove(&root, "ava", 0, 3); cout << "removal !!!!\n";
  remove(&root, "avik", 0, 4); cout << "removal !!!!\n"; 

  findword(root, "ava") == 1 ? cout << "ava exists\n" : cout <<"ava does'nt exists\n";
  findword(root, "avik") == 1 ? cout << "avik exists\n" : cout <<"avik does'nt exists\n";
  findword(root, "avika") == 1 ? cout << "avika exists\n" : cout <<"avika does'nt exists\n";
  return 0;

}
