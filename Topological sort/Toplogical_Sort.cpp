// Time Complexity - O(V + E)
// Space Complexity - O(V + E)


#include<bits/stdc++.h>
using namespace std;

class Graph{

  int V;
  list<int>*adjlist;
  void topologicalSortUtl(int v, bool visited[], stack<int>&S);
public:
  Graph(int v){V = v; adjlist = new list<int>[V];}
  void createedge(int u, int v){

    adjlist[u].push_back(v);
  }
  void topologicalSort();
};


void Graph :: topologicalSortUtl(int v, bool visited[], stack<int>&S){

  visited[v] = true;

  list<int>::iterator it;

  for(it = adjlist[v].begin(); it != adjlist[v].end(); ++it){

      if(!visited[*it]){

        topologicalSortUtl(*it, visited, S);
      }
  }
  
  S.push(v);
}


void Graph :: topologicalSort(){

  stack<int> S;
  bool *visited = new bool[V];

  for(int i = 0; i < V; ++i) visited[i] = false;

  for(int i = 0; i < V; ++i){

    if(!visited[i]){

      topologicalSortUtl(i, visited, S);
    }
  }

  while(!S.empty()){

    cout << S.top() <<" ";
    S.pop();

  }cout << "\n";
}


int main(){

  Graph g(6);
  g.createedge(5, 2);
  g.createedge(5, 0);
  g.createedge(4, 0);
  g.createedge(4, 1);
  g.createedge(2, 3);
  g.createedge(3, 1);

  cout << "Topological sorted edges are - ";
  g.topologicalSort();

  return 0;
}
