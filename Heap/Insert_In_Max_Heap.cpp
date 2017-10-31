#include <bits/stdc++.h>
#define MOD 1000000000
#define ll long long
#define MAX 100000
using namespace std;


void MAXHEAPIFY(int a[], int n, int i)
{

  int left, right, largest;

  left = 2 * i;

  right = 2 * i + 1;

  largest = i;

  if(left <= n && a[left] > a[i]) largest = left;

  if(right <= n && a[right] > a[largest]) largest = right;

  if(largest != i) {


    swap(a[largest], a[i]);
    
    MAXHEAPIFY(a, n, largest);

}

}

int Delete_Max(int a[],int n){

  if(n < 1) {cout<<"Underflow !!!\n"; return -1;}

  int max = a[1], i;

  a[1] = a[n];

  --n;

  for(i = n / 2; i >= 1; --i){

    MAXHEAPIFY(a, n, i);
  
  }

  return max; 

}

void insert(int a[], int val, int n){

  ++n;
  a[n] = val;

  int i = n;

  while(i > 1 && a[i / 2] < a[i]){

    swap(a[i], a[i / 2]);

    i /= 2;

  }

}

int main() {

  int n, a[MAX], i;

  cin >> n;

  for(i = 1; i <= n; ++i) cin >> a[i];

  for(i = n / 2; i >= 1; --i){

    MAXHEAPIFY(a, n, i);

  }

   for(i = 1; i <= n; ++i) cout << a[i] <<" ";

    cout << "\n";

   insert(a, 60, n);

   for(i = 1; i <= n; ++i) cout << a[i] <<" "; 

   return 0;

}