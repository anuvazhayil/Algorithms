int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void checkVal(int x, int y, vector<vector<char>> &result){
    int posx, posy, count = 0;
    for(int i = 0; i < 8; i++){
        posx = x + dx[i];
        posy = y + dy[i];
        if(posx >= 0 && posx < result.size() && posy >=0 && posy < result[0].size() && result[posx][posy] == 'M'){
            count++;
        }
    }
    if(count){
        result[x][y] = char(count+'0');
    }
    else{
        result[x][y] = 'B';
        for(int i = 0; i < 8; i++){
            posx = x + dx[i];
            posy = y + dy[i];
            if(posx >= 0 && posx < result.size() && posy >=0 && posy < result[0].size() && result[posx][posy] == 'E'){
                checkVal(posx, posy, result);
            }
        }
    }
}

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> result = board;
        int x = click.front();
        int y = click.back();
        if(result[x][y] == 'M'){
            result[x][y] = 'X';
            return result;
        }

        checkVal(x, y, result);
        return result;
    }
};
