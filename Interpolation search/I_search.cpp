// Best case - O(lg lg N)// Worst Case - O(N)
#include <bits/stdc++.h>
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define PI 3.14159265
using namespace std; 


int main(){

  ll N, i, start, end, e, num;
  vector<ll>v;

  cin >> N;

  for(i = 0; i < N; ++i) {cin >> num; v.push_back(num);}

  cin >> e;

  sort(v.begin(), v.end());

  start = 0; end = N - 1;

  while(start <= end && e >= v[start] && e <= v[end]){

    ll pos = start + ((double)(end - start) / (v[end] - v[start])) * (e - v[start]); //The idea of formula is to return higher value of pos
                                                                                     //when element to be searched is closer to arr[hi]. And
    if(e == v[pos]) {cout <<"Element Found !!!!"; return 0;}                         //smaller value when closer to arr[lo]

    else if(e > v[pos]) start = pos + 1;

    else if(e < v[pos]) end = pos - 1; 
  
  }

  cout << "Element Not Found !!!";

  return 0;

}