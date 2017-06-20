void dfs(int i, int j, vector<vector<char>> &grid){
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};
    int x, y;
    for(int k = 0; k < 4; k++){
        x = i + dx[k];
        y = j + dy[k];
        if((x >= 0 && x < grid.size()) && (y >= 0 && y < grid[0].size()) && grid[x][y] == '1'){
            grid[x][y] = '0';
            dfs(x, y, grid);
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        if(!grid.size() || !grid[0].size())
            return 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    count++;
                    dfs(i,j, grid);
                }
            }
        }
        return count;
    }
};
