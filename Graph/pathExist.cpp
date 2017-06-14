#include<bits/stdc++.h>

using namespace std;

class Graph{
    int v;
    list<int>*adj;
  public:
    Graph(int v){
        this->v = v;
        adj = new list<int>[v];
    }

    void addEdge(int v, int e){
        adj[v].push_back(e);
    }

    bool checkRoute(int src, int dest){
        vector<bool>visited(v);
        for(int i = 0; i < v; i++)
            visited[i] = false;

        queue<int>q;
        q.push(src);
        visited[src] = true;
        int curr;
        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr == dest)
                return true;
            for(int ele: adj[curr]){
                if(!visited[ele]){
                    visited[ele] = true;
                    q.push(ele);
                }
            }
        }
        return false;
    }
};

int main(){
    bool result;
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    result = g.checkRoute(0, 2);
    if(result)
        cout<<"\nRoute exist between 0 and 2";
    else
        cout<<"\nRoute does not exist between 0 and 2";
    result = g.checkRoute(4, 5);
    if(result)
        cout<<"\nRoute exist between 4 and 5";
    else
        cout<<"\nRoute does not exist between 4 and 5";
    return 0;
}
