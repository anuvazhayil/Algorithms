#include<bits/stdc++.h>

using namespace std;

class Graph{
    int v;
    char *val;
    string *prev;
    list<int> *adj;

  public:
    Graph(int v){
        this->v = v;
        adj = new list<int>[v+1];
        val = new char[v+1];
        prev = new string[v+1];
    }
    int getV(){
        return this->v;
    }
    void vertexEdges(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void addVal(string s){
        vector<int>visited(getV()+1);
        queue<int>q;
        q.push(1);
        visited[1] = 1;
        int curr;

        while(!q.empty()){
            curr = q.front();
            q.pop();
            val[curr] = s[curr-1];
            for(auto edg: adj[curr]){
                if(!visited[edg]){
                    visited[edg] = 1;
                    q.push(edg);
                }
            }
        }
    }

    void getSubs(int u, int v, string pattern){
        vector<int>visited(getV()+1);
        queue<int>q;
        q.push(u);
        visited[u] = 1;
        prev[u] = val[u];
        int curr;

        while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr == v)
                break;
            for(auto edg: adj[curr]){
                if(!visited[edg]){
                    visited[edg] = 1;
                    prev[edg] = prev[curr] + val[edg];
                    q.push(edg);
                }
            }
        }

        int count = 0;
        int pos = prev[curr].find(pattern, 0);
        while(pos != string::npos){
            count++;
            pos = prev[curr].find(pattern, pos+1);
        }
        cout<<count<<"\n";
    }
};

int main(){
    int v, q, u1, u2;
    string s, pattern;
    cin>>v>>q;
    cin>>s;
    cin>>pattern;
    Graph g(v);
    for(int i = 0; i < v-1; i++){
        cin>>u1>>u2;
        g.vertexEdges(u1,u2);
    }
    g.addVal(s);
    for(int i = 0; i < q; i++){
        cin>>u1>>u2;
        g.getSubs(u1,u2, pattern);
    }

    return 0;
}
