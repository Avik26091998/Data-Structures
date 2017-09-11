#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX 100001
#define MOD 1000000007
#define ll long long
using namespace std;

struct node{
	int data;
	node *next;
};

void push_head(node **head,int num){

	node *new_node=new node;
	new_node->data=num;
	if(*head==NULL){

		new_node->next=NULL;
		*head=new_node;
		return;

	}
	new_node->next=*head;
	*head=new_node;
	return;
}

void push_tail(node **head,int num){
  
  node *new_node=new node,*temp=*head;*head=temp;
  new_node->data=num;
  if(*head==NULL){
     new_node->next=NULL;
     *head=new_node;
     return ;
  }
  while(temp->next!=NULL) temp=temp->next;
  temp->next=new_node;
  new_node->next=NULL;
  return;


}
void push_position(node **head,int num,int pos){

	node *temp=*head,*prev=NULL,*head_ref=*head;*head=head_ref;
	node *new_node=new node;
	new_node->data=num;
	int p=1;
	if(pos==1) {push_head(head,num);return;}
    while(p!=pos && temp!=NULL){prev=temp;++p;temp=temp->next;}
    cout<<p<<"\n";
    if(p!=pos&&temp==NULL) {cout<<"Out Of position!!! No ISERTION!!!\n";return;}
    else if(p==pos && temp==NULL) {push_tail(head,num); return;}
    else{
          while(head_ref!=prev) head_ref=head_ref->next;
          prev->next=new_node;
          new_node->next=temp;
          head_ref=prev;
    }

}
void print(node *head){
	while(head!=NULL) {cout<<head->data<<"->";head=head->next;}
	cout<<"NULL\n";
}
int main(){

	int n,pos;
	node *head=NULL;
	cout<<"Enter The Numbers ** 0 to EXIT ** - ";
	cin>>n;
	while(n){
        push_tail(&head,n);
		cin>>n;
	}
	print(head);
	cout<<"Enter the position - ";
	cin>>pos;
	cout<<"Enter the Number To be Inserted - ";
	cin>>n;
    push_position(&head,n,pos);
    cout<<"The Linked List Is - ";
    print(head);
    return 0;
}