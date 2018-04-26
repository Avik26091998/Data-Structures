//complexity - O(logy)

#include<bits/stdc++.h>
#define ll long long int
#define llu unsigned long long int
#define db double

using namespace std;

ll pow(ll x, ll y, ll p){

	ll res = 1;
	x %= p;
	while(y > 0){

		if(y & 1){
			res = (res * x) % p; 
		}

		y >>= 1;
		x = (x * x) % p;
	}
	return res;
}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();
	
	ll x, y;
	cout << pow(10, 6, 13);	   
	


	return 0;
}