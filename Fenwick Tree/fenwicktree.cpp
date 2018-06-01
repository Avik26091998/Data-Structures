
#include <bits/stdc++.h>
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define PI 3.14159265
using namespace std;

int nextindex(int index){

  return index + (index & -index);
}

int parentindex(int index){

  return index - (index & -index);
}

void updateBIT(int BIT[], int value, int index, int size){

  while(index <= size){

    BIT[index] += value;
    index = nextindex(index);
  }

}

int* createBIT(int input[], int n){

  int *BIT = new int[n + 1];

 for(int i = 1; i <= n; ++i){

    updateBIT(BIT, input[i - 1], i, n);
 }

 return BIT; 

} 

int getSum(int BIT[], int index){

  index += 1;
  int sum = 0;
  while(index > 0){

    sum += BIT[index];
    index = parentindex(index);

  }

  return sum;
}

int main(){

  int input[] = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3}, n = 11;
  int *BIT = createBIT(input, n);

  cout << getSum(BIT, 1) <<"\n";
  

  return 0;

}

