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

    vector<int>bfs(int src){
        vector<int>result;
        queue<int>q;
        q.push(src);
        visited[src] = true;
        int curr;

        while(!q.empty()){
            curr = q.front();
            q.pop();
            result.push_back(curr);
            for(auto edg: adj[curr]){
                if(!visited[edg]){
                    visited[edg] = true;
                    q.push(edg);
                }
            }
        }// end of BFS
        return result;
    }
};

int main(){
    Graph g(5);
    g.vertexEdges(1,2);
    g.vertexEdges(1,3);
    g.vertexEdges(1,4);
    g.vertexEdges(2,3);
    g.vertexEdges(2,5);
    g.vertexEdges(3,5);
    g.vertexEdges(4,5);
    g.vertexEdges(3,1);
    vector<int>result = g.bfs(2);

    for(auto ele: result)
        cout<<ele<<" ";

    return 0;
}
