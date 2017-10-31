#include <bits/stdc++.h>
#define MOD 1000000000
#define ll long long
#define MAX 100000
using namespace std;


void MINHEAPIFY(int a[], int n, int i)
{

  int left, right, smallest;

  left = 2 * i;

  right = 2 * i + 1;

  smallest = i;

  if(left <= n && a[left] < a[i]) smallest = left;

  if(right <= n && a[right] < a[smallest]) smallest = right;

  if(smallest != i) {


    swap(a[smallest], a[i]);
    
    MINHEAPIFY(a, n, smallest);

}


}

int main() {

  int n, a[MAX], i;

  cin >> n;

  for(i = 1; i <= n; ++i) cin >> a[i];

  for(i = n / 2; i >= 1; --i){

    MINHEAPIFY(a, n, i);

  }

   for(i = 1; i <= n; ++i) cout << a[i] <<" ";

   return 0;

}
