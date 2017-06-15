#include<bits/stdc++.h>

using namespace std;

//directed graph
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
    }

    void topologicalSort(int i, stack<int> &s){
        for(auto edg: adj[i]){
            if(!visited[edg]){
                visited[edg] = true;
                topologicalSort(edg, s);
            }
        }
        s.push(i);
    }

    stack<int>dfs(int src){
        stack<int>s;
        for(int i = 1; i <= v; i++){
            if(!visited[i]){
                visited[i] = true;
                topologicalSort(i, s);
            }
        }
        return s;
    }
};

int main(){
    Graph g(8);
    g.vertexEdges(1,2);
    g.vertexEdges(1,3);
    g.vertexEdges(1,4);
    g.vertexEdges(2,4);
    g.vertexEdges(3,4);
    g.vertexEdges(3,5);
    g.vertexEdges(3,6);
    g.vertexEdges(4,6);
    g.vertexEdges(7,8);
    stack<int>result = g.dfs(1);

    while(!result.empty()){
        cout<<result.top()<<" ";
        result.pop();
    }

    return 0;
}
