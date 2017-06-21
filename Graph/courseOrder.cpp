class Graph{
    int v;
    vector<int>*edg;
    int *indegree;
    public:
    Graph(int v){
        this->v = v;
        edg = new vector<int>[v];
        indegree = new int[v];
        for(int i = 0; i < v; i++){
            indegree[i] = 0;
        }
    }

    void edges(int i, int j){
        edg[j].push_back(i);
        cout<<i<<"\n";
        indegree[i] += 1;
    }

    vector<int> dfs(){
        vector<int>order;
        vector<int>visited(v);
        for(int i = 0; i < v; i++){
            if(indegree[i] == 0 && !visited[i]){
                order.push_back(i);
                visited[i] = 1;
                checkOrder(i, visited, order);
            }
        }
        return order;
    }

    void checkOrder(int i, vector<int> &visited, vector<int> &order){
        for(auto neigh: edg[i]){
            indegree[neigh] -= 1;
            if(indegree[neigh] == 0 && !visited[neigh]){
                order.push_back(neigh);
                visited[neigh] = 1;
                checkOrder(neigh, visited, order);
            }
        }
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int>result;
        Graph g(numCourses);
        int len = prerequisites.size();
        for(int i = 0; i < len; i++){
            g.edges(prerequisites[i].first, prerequisites[i].second);
        }
        result = g.dfs();
        if(result.size() == numCourses)
            return result;
        else
            return vector<int>();
    }
};
