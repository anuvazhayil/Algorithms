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
        indegree[i] += 1;
    }

    bool dfs(){
        int count = 0;
        vector<int>visited(v);
        for(int i = 0; i < v; i++){
            if(indegree[i] == 0 && !visited[i]){
                count++;
                visited[i] = 1;
                visitneigh(i, visited, count);
            }
        }
        if(count == v)
            return true;
        else
            return false;
    }

    void visitneigh(int i, vector<int>&visited, int &count){

        for(auto neigh: edg[i]){
            indegree[neigh] -= 1;
            if(indegree[neigh] == 0 && !visited[neigh]){
                count++;
                visited[neigh] = 1;
                visitneigh(neigh, visited, count);
            }
        }

    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        bool result;
        Graph g(numCourses);
        int len = prerequisites.size();
        for(int i = 0; i < len; i++){
            g.edges(prerequisites[i].first, prerequisites[i].second);
        }
        result = g.dfs();

        if(result)
            return true;
        else
            return false;
    }
};
