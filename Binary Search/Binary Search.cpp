#include <bits/stdc++.h>
#define MAX 100001
#define MOD 1000000007
#define ll long long
using namespace std;

void Binary_Search(int a[], int low, int high, int element){

  if(low > high) {cout << "Element Not Found !!!"; return;} 
  
  int mid = low + (high - low) / 2;

  if(a[mid] == element) {cout << "Element Found !!!";return;}

  else if(element < a[mid]) Binary_Search(a, low, mid - 1, element);

  else if(element > a[mid]) Binary_Search(a, mid + 1, high, element);

}

int main(){

  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int N, a[100000], i;

  cin >> N;

  for(i = 1; i <= N; ++i) cin >> a[i];     // Input Sorted Array

  Binary_Search(a, 1, N, 5);

  return 0;

}