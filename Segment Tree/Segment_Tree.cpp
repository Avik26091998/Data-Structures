#include <bits/stdc++.h>
#define MAX 100001
#define MOD 1000000007
#define ll long long
using namespace std;

void Build(ll a[], ll segment[], ll low, ll high, ll pos){

  if(low == high){

    segment[pos] = a[low];
    return;
  }
  ll mid = (low + high) / 2;

  Build(a, segment, low, mid, 2 * pos);
  Build(a, segment, mid + 1, high, 2 * pos + 1);

  segment[pos] = min(segment[2 * pos], segment[2 * pos + 1]);

}

ll Querying(ll segment[], ll q_low, ll q_high, ll low, ll high, ll pos){

  if(q_low <= low && q_high >= high) return segment[pos];

  else if(q_low > high || q_high < low) return INT_MAX;

  else{

    ll mid = (low + high) / 2;

    return min(Querying(segment, q_low, q_high, low, mid, 2 * pos), Querying(segment, q_low, q_high, mid + 1, low, 2 * pos + 1));
  }

}

void update(ll a[], ll segment[], ll low, ll high, ll index, ll value, ll pos){

   
   if(low == high){

    a[index] = value;
    segment[pos] = value;
    return;
   }
   

   ll mid = (low + high) / 2;

   if(low <= index && index <= mid) update(a, segment, low, mid, index, value, 2 * pos);

   else update(a, segment, mid + 1, high, index, value, 2 * pos + 1);

   segment[pos] = min(segment[2 * pos], segment[2 * pos + 1]);
  
}





int main(){

  ll N, i;

  cin >> N;

  ll a [N + 1], segment[4 * N + 1];

  for(i = 1; i <= N; ++i) cin >> a[i];

  Build(a, segment, 1, N, 1);

  cout <<  Querying(segment, 1, N, 1, N, 1) <<"\n";

  update(a, segment, 1, N, 2, -2, 1);

  cout << Querying(segment, 1, N, 1, N, 1);

  
  return 0;

}
