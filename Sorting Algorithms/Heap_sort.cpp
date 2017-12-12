// complexity - O(nlogn)

//sapce - O(1)

#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000007
     
using namespace std;

void MAX_HEAPIFY(ll a[], ll n, ll i){

	ll left, right, max_index;

	left = 2 * i;
	right = 2 * i + 1;

	max_index = i;

	if(left <= n && a[max_index] < a[left]){

		max_index = left;
	}
	if(right <= n && a[right] > a[max_index]){

		max_index = right;
	}
	if(max_index != i){

		swap(a[max_index], a[i]);
		MAX_HEAPIFY(a, n, max_index);
	}
	else return;
}

void HEAP_SORT(ll a[], ll n){

	if(n == 0) return;
	swap(a[1], a[n]);
	cout << a[n] <<" ";
	--n;
	for(ll i = n / 2; i >= 1; --i){

   		MAX_HEAPIFY(a, n, i);
   	}
   	HEAP_SORT(a, n);


}

int main(){
 
   ll i, a[100000], n;

   cin >> n;
   for(i = 1; i <= n; ++i) cin >> a[i];

   	for(i = n / 2; i >= 1; --i){

   		MAX_HEAPIFY(a, n, i);
   	}

   	HEAP_SORT(a, n);

   	
   return 0;
}
