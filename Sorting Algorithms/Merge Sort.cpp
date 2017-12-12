/*   Merge Sort
     ----------
  Best - ohm(nlogn)
  Average - theta(nlogn)
  Worst - O(nlogn)

  Space - O(n)

 */
#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000007
     
using namespace std;

void Merge(ll a[], ll left[], ll right[], ll nl, ll nr){

	ll left_count = 1, right_count = 1, k = 1;

	while(left_count <= nl && right_count <= nr){

		if(left[left_count] <= right[right_count]){
			a[k++] = left[left_count++];
		}
		else a[k++] = right[right_count++];
	}
	while(left_count <= nl){
		a[k++] = left[left_count++];
	}
	while(right_count <= nr){
		a[k++] = right[right_count++];
	}
}

void Merge_sort(ll a[], ll n){

	if(n < 2) return;

	ll nl = n / 2, nr = n - nl, i, left[nl], right[nr];

	for(i = 1; i <= nl; ++i) left[i] = a[i];
	for(i = nl + 1; i <= n; ++i) right[i - nl] = a[i];

	Merge_sort(left, nl);
    Merge_sort(right, nr);
    Merge(a, left, right, nl, nr);

}

int main(){
 
  ll n, a[100000], i;

  cin >> n;

  for(i = 1; i <= n; ++i) cin >> a[i];

  Merge_sort(a, n);

  for(i = 1; i <= n; ++i) cout << a[i] <<" ";
  
  return 0;

}