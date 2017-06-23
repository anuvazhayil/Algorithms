void dfs(vector<vector<int>> &M, int i, int j){
    for(int k = 0; k < M.size(); k++){
        if(M[i][k]){
            M[i][k] = 0;
            M[k][i] = 0;
            dfs(M, i, k);
        }
        if(M[k][j]){
            M[k][j] = 0;
            M[j][k] = 0;
            dfs(M, k, j);
        }
    }
    return;
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        for(int i = 0; i < M.size(); i++){
            for(int j = 0; j <= i; j++){
                if(M[i][j]){
                    count++;
                    M[i][j] = 0;
                    M[j][i] = 0;
                    dfs(M, i, j);
                }
            }
        }
        return count;
    }
};
