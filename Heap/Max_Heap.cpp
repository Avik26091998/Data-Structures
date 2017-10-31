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

int main() {

  int n, a[MAX], i;

  cin >> n;

  for(i = 1; i <= n; ++i) cin >> a[i];

  for(i = n / 2; i >= 1; --i){

    MAXHEAPIFY(a, n, i);

  }

   for(i = 1; i <= n; ++i) cout << a[i] <<" ";

   return 0;

}