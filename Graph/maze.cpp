#include<bits/stdc++.h>

using namespace std;

const int ROW_MAX = 4;
const int COL_MAX = 5;

class Cell{
    public:
    int x, y;
    int val;
    bool visited;
    Cell *parent;
    Cell(){
      this->x = this->y = this->val = 0; this->visited = false; this->parent = NULL;
    }
    Cell(int x, int y, int val){
        this->x = x;
        this->y = y;
        this->val = val;
        this->visited = false;
        this->parent = NULL;
    }
};

class Maze{
    Cell **maze;
    public:

    Maze(int **pattern){
        maze = new Cell *[ROW_MAX];
        for(int i = 0; i < ROW_MAX; i++)
            maze[i] = new Cell[COL_MAX];

        for(int i = 0; i < ROW_MAX; i++)
            for(int j = 0; j < COL_MAX; j++)
                maze[i][j] = Cell(i, j, pattern[i][j]);
    }

    Cell* getValue(int x, int y){
        return &maze[x][y];
    }

    Cell* showPath(int srcx, int srcy, int destx, int desty){
        queue<Cell*>q;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};
        Cell *src = getValue(srcx, srcy);
        src->visited = true;
        q.push(src);
        Cell *curr;

        while(!q.empty()){
            int posx, posy;
            curr = q.front();
            q.pop();

            if(curr->x == destx && curr->y == desty){
                break;
            }

            for(int i = 0; i < 4; i++){
                posx = curr->x + dx[i];
                posy = curr->y + dy[i];

                if(posx >= 0 && posx < ROW_MAX && posy >= 0 && posy < COL_MAX){
                    Cell *next = getValue(posx, posy);
                    if(!next->visited && next->val){
                        next->visited = true;
                        next->parent = curr;
                        q.push(next);
                    }
                }
            }
        }
        return curr;
    }

    void printRev(Cell *result){
        if(!result){
            return;
        }
        printRev(result->parent);
        cout<<" ("<<result->x<<","<<result->y<<")->";
    }
};

int main(){
    int **pattern;
    pattern = new int *[ROW_MAX];
    for(int i = 0; i < ROW_MAX; i++)
        pattern[i] = new int[COL_MAX];

    int maze_data[][COL_MAX] = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 1, 1, 1, 1}};
    for(int i = 0; i < ROW_MAX; i++)
        for(int j = 0; j < COL_MAX; j++)
            pattern[i][j] = maze_data[i][j];

    Maze board(pattern);
    Cell *result = board.showPath(1, 0, 2, 2);
    board.printRev(result);
    cout<<"Destination Reached!";
    return 0;
}
