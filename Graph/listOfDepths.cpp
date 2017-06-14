#include<bits/stdc++.h>

using namespace std;

class Graph{
    int v;
    int depth;
    list<int> *adj;
    int *count;
  public:
    Graph(int d, int v){
        this->depth = d;
        this->v = v;
        adj = new list<int>[v];
        count = new int[v];
        for(int i = 0; i < v; i++)
            count[i] = 0;
    }

    void addChild(int v, list<int>children){
        adj[v] = children;
    }

    list<int>* depthList(int root){
        list<int> *result = new list<int>[depth];
        queue<int>q;
        q.push(root);
        result[0].push_back(root);
        vector<int>row;
        int curr, rowCount = 0;

        while(!q.empty()){
            curr = q.front();
            q.pop();

            for(auto ele: adj[curr]){
                count[ele] = count[curr]+1;
                result[count[ele]].push_back(ele);
                q.push(ele);
            }
        }
        return result;
    }
};

int main(){
    int depth = 3, vertices = 13;
    Graph g(depth, vertices);
    list<int> *result = new list<int>[depth];
    g.addChild(0, {1,2,3});
    g.addChild(1, {4,5,6});
    g.addChild(2, {7,8,9});
    g.addChild(3, {10,11,12});
    result = g.depthList(0);
    for(int i = 0; i < depth; i++){
        cout<<"Row "<<i+1<<" contains: ";
        for(auto ele: result[i]){
            cout<<ele<<"->";
        }
        cout<<"NULL \n";
    }

    return 0;
}
