#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000000
     
using namespace std;


struct Node{

  int isWord;
  Node *child[26];

};

Node* NewNode(){

  Node *new_node = new Node;
  new_node->isWord = 0;
  for(int i = 0; i < 26; ++i) new_node->child[i] = NULL;

  return new_node;
}

Node* addword(Node *root, string s){

  Node *temp = root;
  root = temp;
  for(int i = 0; i < s.length(); ++i){

    int ch = s[i] - 'a';

    if(temp->child[ch] == NULL) temp->child[ch] = NewNode();

    temp = temp->child[ch];
  }
  temp->isWord = 1;

  return root;
}

int FindWord(Node *root, string s){

  Node *temp = root;

  int ch;

  for(int i = 0; i < s.length(); ++i){

    ch = s[i] - 'a';

    if(temp->child[ch] == NULL) return 0;
    temp = temp->child[ch];
  }
  if(temp->isWord == 1) return 1;
  
  return 0;
}

int isEmpty(Node *root){

  for(int i = 0; i < 26; ++i){

    if(root->child[i] != NULL) return 1;
  }
  return 0;

}

void Remove(string s, Node *temp,int index, int n){

  if(temp == NULL) return;
  if(index == n){

    temp->isWord = 0;
    if(isEmpty(temp)) delete[] temp;
    return;
  }
  Remove(s, temp->child[s[index] - 'a'], index + 1, n);
}


int main(){

 // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  Node *root = NewNode();
  root = addword(root, "avik");
  root = addword(root, "pogba");
  root = addword(root, "manchester");
  root = addword(root, "manu");
  
  cout << FindWord(root, "k") << "\n";
  cout << FindWord(root, "pogba") <<"\n";
  cout << FindWord(root, "manchester") <<"\n";
  cout << FindWord(root, "manc") <<"\n";

  Remove("k", root, 0, 1);
  cout << FindWord(root, "k");

  return 0;

}