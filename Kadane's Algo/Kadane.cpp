//Time complexity-O(n)
//Space Complexity-O(n)

#include<iostream>
using namespace std;

int main(){

	int n, a[100001], local_max, global_max;
	cin >> n;

	for(int i = 1;i <= n; ++i) cin >> a[i];
	local_max=0;	
	global_max=INT_MIN;

	for(int i = 1;i <= n; ++i){

		local_max=max(a[i], a[i] + local_max);
		if(local_max > global_max) global_max=local_max;
	}

	cout << global_max;

}