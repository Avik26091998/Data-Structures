// Difference Array O(1) range update

    #include<bits/stdc++.h>
    using namespace std;
     
    int main(){

      int n, a[100001], D[100001], l, r, x;

      cin >> n;
      for(int i = 0; i < n; ++i){

        cin >> a[i];
        if(i > 0) D[i] = a[i] - a[i - 1];
      }

      D[0] = a[0];

      cin >> l >> r >> x;

      D[l] += x; D[r + 1] -= x;

      for(int i = 0; i < n; ++i){

        if(i == 0) a[0] = D[0];
        else a[i] = D[i] + a[i - 1];

        cout << a[i] <<" ";
      }cout <<"\n";

      return 0;

    }

