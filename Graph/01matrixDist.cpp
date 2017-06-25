int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void bfs(queue<pair<int,int>> q, vector<vector<int>> &matrix, vector<vector<int>> &result){
    int i, j, x, y;
    while(!q.empty()){
        i = q.front().first; j = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            x = i + dx[k];
            y = j + dy[k];
            if(x >= 0 && x < matrix.size() && y >=0 && y < matrix[0].size() && matrix[x][y]){
                if(result[i][j]+1 < result[x][y]){
                    result[x][y] = result[i][j] + 1;
                    q.push(make_pair(x, y));
                }
            }
        }
    }
}

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>result(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        queue<pair<int, int>>q;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(!matrix[i][j]){
                    result[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        bfs(q, matrix, result);
        return result;
    }
};
