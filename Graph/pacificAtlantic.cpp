int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(vector<vector<int>> &matrix, int row, int col, vector<vector<bool>> &ocean){
    int x, y;
    ocean[row][col] = true;
    for(int i = 0; i < 4; i++){
        x = row + dx[i];
        y = col + dy[i];
        if(x >= 0 && x < matrix.size() && y >=0 && y < matrix[0].size() && matrix[x][y] >= matrix[row][col] && !ocean[x][y]){
            dfs(matrix, x, y, ocean);
        }
    }
}

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if(!matrix.size())
            return vector<pair<int, int>>();
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            dfs(matrix, i, 0, pacific);
            dfs(matrix, i, n-1, atlantic);
        }
        for(int j = 0; j < n; j++){
            dfs(matrix, 0, j, pacific);
            dfs(matrix, m-1, j, atlantic);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back(make_pair(i,j));
            }
        }
        return res;
    }
};
