#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph{

  int V;
  list<int> *adjlist;
  void DFSUtil(int v, bool visited[]);

public:

  Graph(int v){

    V = v;
    adjlist = new list<int>[V];
  }

  void addEdge(int u, int v){

    adjlist[u].push_back(v);
  }

  void DFS(int v);

};

void Graph::DFSUtil(int v, bool visited[]){

  visited[v] = true;
  cout << v <<" ";

  list<int>::iterator it;

  for(it = adjlist[v].begin(); it != adjlist[v].end(); ++it){

    if(!visited[*it]) DFSUtil(*it, visited);
  }

}

void Graph::DFS(int v){

  bool *visited = new bool[V];
  for(int i = 0; i < V; ++i) visited[i] = false;
  DFSUtil(v, visited);

  // for(int i = 0; i < V; ++i){          for Unconnected graph

  //   if(visited[i] == false) DFSUtil(i, visited);
  // }

}


int main(){

  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.DFS(2);        // Start DFS from vertex - 

  return 0;
}