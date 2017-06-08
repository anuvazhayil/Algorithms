#include<bits/stdc++.h>

using namespace std;

class Cell{
    public:
    int x, y;
    int value;
    bool visited;
    Cell parent;
    Cell(int x, int y, int val, bool visited, Cell parent){
        this.x = x;
        this.y = y;
        this.val = val;
        this.visited = false;
        this.parent = NULL;
    }
}

class Maze{
    Cell[][] maze;
    public:
    Maze(int[][] pattern){
        for(int i = 0; i < pattern.size(); i++){
            for(int j = 0; j < pattern[0].size(); j++){
                maze[i][j] = {i, j, pattern[i][j], false, NULL};
            }
        }
    }

    Cell* getValue(int x, int y){
        return maze[x][y];
    }

    void showPath(int srcx, int srcy, int destx, int desty){
        queue<cell>q;
        vector<int>result;
        q.push({srcx, srcy, 1, true, NULL});
        // BFS
        while(!q.empty()){

        }
    }
}

int main(){
    vector<Cell>result;
    int[][] pattern = {{1, 0, 1, 1, 1},
                       {1, 0, 1, 0, 1},
                       {1, 0, 1, 0, 1},
                       {1, 1, 1, 1, 1}};

    Maze board(pattern);
    result = board.showPath(1, 0, 2, 2);
    for(auto ele: result){
        cout<<"("<<ele.x<<","<<ele.y<<") ->";
    }
    cout<<"Destination Reached!";
    return 0;
}
