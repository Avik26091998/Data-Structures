#include <bits/stdc++.h>
#define MOD 1000000000
#define ll long long
#define MAX 100000
#define SIZE 5
using namespace std;

int front = -1, rear = -1, a[SIZE];


void EnqueueFront(int num){

  if(front == -1 && rear == -1){

    front = rear = 0;
  }
  else if(front - 1 == rear){

    cout << "Dequeue is Full !!!";

    return;
  }
  else if(front == 0){

    front = SIZE - 1;
  }
  else front -= 1;

  a[front] = num;
}

void EnqueueRear(int num){

  if(front == -1 && rear == -1){

    front = rear = 0;
  }
  else if(rear + 1 == front){

    cout << "Dequeue is Full !!!";

    return;
  }
  else if(rear == SIZE - 1){

    rear = 0;
  }
  else rear += 1;

  a[rear] = num;

}

int DequeueFront(){

  int n = a[front];

  if(front == -1 && rear == -1){

    cout <<"Dequeue is Empty!!!";

    return -1;
  }
  else if(front == rear){

    front = rear = -1;
  }
  else if(front == SIZE - 1){

    front = 0;
  }
  else front += 1;

  return n;
}

int DequeueRear(){

  int n = a[rear];

  if(front == -1 && rear ==  -1){

    cout << "Dequeue is Empty!!!";

    return -1;

  }
  else if(front == rear){

    front = rear = -1;

  }
  else if(rear == 0){

    rear = SIZE - 1;
  }
  else rear -= 1;

  return n;
}


int main(){

  EnqueueRear(20);
  EnqueueRear(30);
  EnqueueRear(40);
  EnqueueRear(50);
  EnqueueFront(10);
  cout << DequeueFront() << "\n";
  cout << DequeueRear() << "\n";




  return 0;
}