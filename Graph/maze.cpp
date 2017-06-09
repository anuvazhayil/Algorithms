#include<bits/stdc++.h>

using namespace std;

class Cell{
    public:
    int x, y;
    int val;
    bool visited;
    Cell parent;
    Cell(int x, int y, int val, bool visited){
        this->x = x;
        this->y = y;
        this->val = val;
        this->visited = false;
    }
};

class Maze{
    Cell maze[][5];
    public:
    Maze(int pattern[][5]){
        int rows = sizeof(pattern)/sizeof(pattern[0]);
        int cols = sizeof(pattern[0])/sizeof(int);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                Cell *ptr = &maze[i][j].parent;
                ptr = NULL;
                maze[i][j] = Cell(i, j, pattern[i][j], false);

            }
        }
    }

    Cell getValue(int x, int y){
        return maze[x][y];
    }

    stack<Cell> showPath(int srcx, int srcy, int destx, int desty, int rows, int cols){
        queue<Cell>q;
        stack<Cell>result;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        Cell src = getValue(srcx, srcy);
        src.visited = true;
        q.push(src);
        Cell curr;

        while(!q.empty()){
            int posx, posy;
            curr = q.front();
            q.pop();

            if(curr.x == destx && curr.y == desty){
                break;
            }

            for(int i = 0; i < 4; i++){
                posx = curr.x + dx[i];
                posy = curr.y + dy[i];
                Cell next = getValue(posx, posy);
                if(posx >=0 && posx < rows && posy >= 0 && posy < cols && !next.visited && next.val){
                    next.visited = true;
                    next.parent = curr;
                    q.push(next);
                }
            }
        }
        while(curr.parent != NULL){
            result.push(curr);
            curr = curr.parent;
        }
        return result;
    }
};

int main(){
    stack<Cell>result;
    int pattern[][5] = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 1, 1, 1, 1}};

    Maze board(pattern);
    result = board.showPath(1, 0, 2, 2, 4, 5);
    while(!result.empty()){
        Cell ele = result.top();
        result.pop();
        cout<<"("<<ele.x<<","<<ele.y<<") ->";
    }
    cout<<"Destination Reached!";
    return 0;
}
