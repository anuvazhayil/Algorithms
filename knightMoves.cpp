#include<bits/stdc++.h>

using namespace std;

struct chess{
    int posx, posy, dist;
};

int findMoves(pair<int, int>curr, pair<int, int>dest){

    vector<vector<int> >board(8, vector<int> (8));
    queue<chess>q;
    chess box;
    //possible eight directions
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    board[curr.first][curr.second] = 1;
    q.push({curr.first, curr.second, 0});

    while(!q.empty()){
        box = q.front();
        q.pop();

        if(box.posx == dest.first && box.posy == dest.second){
            return box.dist;
        }

        for(int i = 0; i < 8; i++){
            int x = box.posx + dx[i];
            int y = box.posy + dy[i];
            if(x >= 0 && x < 8 && y >= 0 && y < 8 && !board[x][y]){
                board[x][y] = 1;
                q.push({x, y, box.dist+1});
            }
        }
    }
}

int main(){
    int T;
    string a, b;
    pair<int, int>curr, dest;
    cin>>T;

    while(T){
        cin>>a;
        cin>>b;
        pair<int, int>curr, dest;
        curr = {a[0]-'a', a[1]-'1'};
        dest = {b[0]-'a', b[1]-'1'};
        cout<<curr.first<<" "<<curr.second;
        cout<<"\n"<<dest.first<<" "<<dest.second;
        int res = findMoves(curr, dest);
        cout<<res<<"\n";
        T--;
    }
    return 0;
}
