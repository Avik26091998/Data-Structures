//  build_tree: O(N lg(N))  
//  update_tree: O(lg(N + k))
//  query_tree: O(lg(N + k))
// 
//  k - No. of segments

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int arr[10001], tree[4*10001], lazy[4*10001];



void build_tree(int node, int a, int b){

    if(a > b) return;
    if(a == b){
        
        tree[node] = arr[a];
        return;
    }

    build_tree(2 * node, a, (a + b) / 2);
    build_tree(2 * node + 1, 1 +((a + b) / 2) , b);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);

}

void update_tree(int node, int a, int b, int i, int j, int value){


    if(lazy[node] != 0){

        tree[node] += lazy[node];

        if(a != b){

            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(a > b || a > j || b < i) return;

    if(a >= i && b <= j){

        tree[node] += value;

        if(a != b){       // Not leaf node
    
            lazy[node * 2] += value;

            lazy[node * 2 + 1] += value;
        }

        return;
    }

    update_tree(node * 2, a, (a + b) / 2, i, j, value);
    update_tree(node * 2 + 1, 1 + (a + b) / 2, b, i, j, value);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);

}


int query_tree(int node, int a, int b, int i, int j){

    if(a > b || a > j || b < i) return INT_MIN;

    if(lazy[node] != 0){

        tree[node] += lazy[node];

        if(a != b){

            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(a >= i && b <= j) return tree[node];

    int q1 = query_tree(node, a, (a + b) / 2, i, j);
    int q2 = query_tree(node, 1 + (a + b) / 2, b, i, j);

    return max(q1, q2);

}

int main(){

    int n;
    
    memset(lazy, 0, sizeof lazy);
    
    cin >> n;

    for(int i = 0; i < n; ++i) cin >> arr[i];

    build_tree(1, 0, n - 1);
    
    update_tree(1, 0, n - 1, 1, 2, 1);
    //update_tree(1, 0, n - 1, 2, 3, 1);

    cout << query_tree(1, 0, n - 1, 0, 1);


    return 0;

}