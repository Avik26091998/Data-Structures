    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;

    int block[100001];
    int block_size = sqrt(n), block_index = -1;

    void preprocess(int arr[], int n){ 

        for(int i = 0; i < n; ++i){

          if(i % block_size == 0) ++block_index;
           
           block[block_index] += arr[i]; 
        }

        //for(int i = 0; i <= block_index; ++i) cout << block[i] <<" | ";
        
    }


    int query(int l, int r, int arr[]){

      int sum = 0;
      while(l < r && l % block_size != 0 && l != 0){

          sum += arr[l];
          ++l;
      }

      while(l + block_size <= r){

          sum += block[l / block_size];
          l += block_size;
      }

      while(l <= r){

        sum += arr[l];
        ++l;
      }

      return sum;

    }

    void update(int arr[], int index, int val){

        block[index / block_size] += val - arr[index];
        arr[index] += val;
    }

    int main(){

      int n = 9, arr[10] = {1, 5, 2, 4, 6, 1, 3, 5, 7};
      preprocess(arr, n);

      
      query(l, r, arr);
      update(arr, index, val);

    }