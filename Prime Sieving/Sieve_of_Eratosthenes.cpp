#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000000
     
using namespace std;


void Prime(ll n){

  bool p[n + 1];

  memset(p, true, sizeof(p));

  for(ll i = 2; i * i <= n; ++i){

    if(p[i] == true){

      for(ll j = i * 2; j <= n; j += i){

        p[j] = false;
      }
    }
  }

  for(ll i = 2; i <= n; ++i){

    if(p[i] == true) cout << i <<" ";
  }
}    
    



int main(){

   ll n;

   cin >> n;

   Prime(n);

   return 0;
  
}