class Graph{
    int v;
    list<int> *adj;
    public:
        Graph(int v){
            this->v = v;
            adj = new list<int>[v];
        }
        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void dfs(int vno, int level, vector<int> &visited, int &max){
            for(int ele: adj[vno]){
                if(!visited[ele]){
                    visited[ele] = 1;
                    dfs(ele, level+1, visited, max);
                }
            }
            if(level > max)
                max = level;
        }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>>root_ht;

        int min = INT_MAX, max;
        Graph g(n);
        for(auto ele: edges)
            g.addEdge(ele.first, ele.second);

        for(int i = 0; i < n; i++){
            vector<int> visited(n);
            visited[i] = 1;
            max = 0;
            g.dfs(i, 0, visited, max);
            root_ht[max].push_back(i);
        }

        for(auto ele: root_ht){
            if(ele.first < min)
                min = ele.first;
        }
        return root_ht.at(min);
    }
};
