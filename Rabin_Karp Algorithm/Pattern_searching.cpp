//  Rabin - Karp Algorithm
//    
//  n - text length
//
//  m - pattern length
//
//  Best/ Average - O(n + m)
//  Worst - O(nm)

//  Space - O(1)
 

#include<bits/stdc++.h>
#define ll long long
#define PRIME 101
using namespace std;


ll hash_fun(string s, int n){

	ll num = 0;
	for(int i = 0; i <= n; ++i){

		num += s[i] * pow(PRIME, i);
	}
	return num;
}

ll recreate(int oldindex, string text, int newindex, ll old_hash, int pattern_len){

	ll new_hash = old_hash - text[oldindex];
	new_hash /= PRIME;
	new_hash += text[newindex] * pow(PRIME, pattern_len - 1);

	return new_hash;

}

int Rabin_Karp(string pattern, string text){

	int m = pattern.length(), n = text.length();

	ll pattern_hash = hash_fun(pattern, m - 1);
	ll text_hash = hash_fun(text, m - 1);

	for(int i = 1; i <= n - m + 1; ++i){

		if(pattern_hash == text_hash && pattern.substr(0, m) == text.substr(i - 1, m)) return i - 1;
		if(i < n - m + 1) text_hash = recreate(i - 1, text, i + m - 1, text_hash, m);
	}

	return -1;
}

int main(){


	string text = "avik", pattern = "vi";

	cout << Rabin_Karp(pattern, text);     // Starting index of pattern in text

	return 0;
}
