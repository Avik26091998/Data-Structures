// Complexity - O(V + E)

#include<bits/stdc++.h>
#define ll long long int
#define llu unsigned long long int
#define db double
#define bsa(v,n,a) binary_search(v,v+n,a)
#define bsv(v,a) binary_search(v.begin(),v.end(),a)
#define PI 3.1415926535897932
using namespace std;
// #define db eps=1e-6;
// #define db inf=1e-9;
// #define ll INF=1e15+100;
// #define ll mod=1e9+7;
// #define ll MAX=1e6+1;

 
enum Color{WHITE, GRAY, BLACK};

 class Graph{

 	int V;
 	list<int> *adj_list;
 	bool detectCycleUtil(int v, int color[]);

public:

 	Graph(int V);
 	void addEdge(int u, int v);
 	bool detectCycle();
 };

 Graph::Graph(int V){

 	this->V = V;
 	adj_list = new list<int>[V];
}	

void Graph::addEdge(int u, int v){

	adj_list[u].push_back(v);
}

bool Graph::detectCycleUtil(int v, int color[]){

	color[v] = GRAY;
	list<int>::iterator it;

	for(it = adj_list[v].begin(); it != adj_list[v].end(); ++it){

			if(color[*it] == GRAY) return true;
			if(color[*it] == WHITE && detectCycleUtil(*it, color)) return true;
	}

	color[v] = BLACK;
	return false;
}

bool Graph::detectCycle(){

	int *color = new int[V];

	for(int i = 0; i < V; ++i) color[i] = WHITE;

	for(int i = 0; i < V; ++i){

		if(color[i] == WHITE){

			if(detectCycleUtil(i, color)) return true;
		}
	}
	return false;
}

 int main(){

 	Graph g(5);
 	g.addEdge(0, 1);
 	g.addEdge(1, 2);
 	g.addEdge(0, 2);

 	if(g.detectCycle()) cout <<"Graph has a Cycle";
 	else cout<<"Graph has no cycle";

   return 0;
}