class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>pathsum(n, vector<int>(m, INT_MAX));
        pathsum[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
            pathsum[i][0] = pathsum[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < m; j++){
            pathsum[0][j] = pathsum[0][j-1] + grid[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                pathsum[i][j] = min(pathsum[i][j-1], pathsum[i-1][j]) + grid[i][j];
            }
        }
        return pathsum[n-1][m-1];
    }
};
