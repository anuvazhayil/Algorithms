int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        q.push(make_pair(start[0], start[1]));

        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            if((i == destination[0]) && (j == destination[1]))
                return true;
            int x, y;
            for(int k = 0; k < 4; k++){
                x = i + dx[k];
                y = j + dy[k];
                while(x >= 0 && x < n && y >= 0 && y < m && !maze[x][y]){
                    x += dx[k];
                    y += dy[k];
                }
                if(!visited[x-dx[k]][y-dy[k]]){
                    visited[x-dx[k]][y-dy[k]] = 1;
                    q.push(make_pair(x-dx[k], y-dy[k]));
                }
            }
        }
        return false;
    }
};
