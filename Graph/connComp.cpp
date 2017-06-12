#include<bits/stdc++.h>

using namespace std;

//undirected graph
class Graph{
    int v;
    bool *visited;
    list<int> *adj;

  public:
    Graph(int v){
        this->v = v;
        visited = new bool[v+1];
        for(int i = 1; i <= v; i++)
            visited[i] = false;
        adj = new list<int>[v+1];
    }

    void vertexEdges(int vs, int e){
        adj[vs].push_back(e);
        adj[e].push_back(vs);
    }

    void dfs(int src){
        stack<int>s;
        s.push(src);
        visited[src] = true;
        int curr;

        while(!s.empty()){
            curr = s.top();
            s.pop();
            
            for(auto edg: adj[curr]){
                if(!visited[edg]){
                    visited[edg] = true;
                    s.push(edg);
                }
            }
        }// end of DFS
    
    }

    int connComp(){
        int count = 0;
        for(int i = 1; i <= v; i++){
            if(!visited[i]){
                ++count;
                dfs(i);
            }
        }
        return count;
    }
};

int main(){
    Graph g(6);
    g.vertexEdges(1,2);
    g.vertexEdges(2,3);
    g.vertexEdges(4,5);
    
    int result = g.connComp();

    cout<<"Number of connected components: "<<result;

    return 0;
}
