    // Time Complexity - O(V + E)

    #include<bits/stdc++.h>
    using namespace std;
     
    class Graph{

      int V;
      int color;
      list<int>*adj_list;
      void DFSUtil(int start, bool visited[]);
    public:
      Graph(int v){V = v; adj_list = new list<int>[V]; color = 0;}
      void Create_Edge(int u, int v){adj_list[u].push_back(v); adj_list[v].push_back(u);}
      void Connected(){

        bool *visited = new bool[V];
        for(int i = 0; i < V; ++i) visited[i] = false;

        for(int i = 0; i < V; ++i){
          if(visited[i] == false) {++color ;visited[i] = true; DFSUtil(i, visited); cout <<"---- Colored with --- "<< color <<" \n";}  // Flood Fill - Labelling the Connected Components
        }
      }

    };

    void Graph :: DFSUtil(int start, bool visited[]){

      cout << start <<" ";
      list<int>::iterator it;

      for(it = adj_list[start].begin(); it != adj_list[start].end(); ++it){
        if(!visited[*it]){

          visited[*it] = true;
          DFSUtil(*it, visited);
        }
      }

    }

    int main(){

      Graph g(8);
      g.Create_Edge(0, 1);
      g.Create_Edge(1, 2);
      g.Create_Edge(2, 3);
      g.Create_Edge(1, 3);
      g.Create_Edge(3, 4);
      g.Create_Edge(6, 7);

      g.Connected();

      return 0;
    }
