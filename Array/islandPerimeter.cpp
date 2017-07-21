int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), island = 0, count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    island++;
                    for(int k = 0; k < 4; k++){
                        int nx = i+x[k], ny = j+y[k];
                        if(nx >= 0 && nx < m && ny >=0 && ny < n)
                            if(grid[nx][ny] == 1)
                                count++;
                    }
                }
            }
        }
        return 4*island-count;
    }
};
