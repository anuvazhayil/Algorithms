#include<bits/stdc++.h>

using namespace std;

struct Floor{
    int val, bpush;
};

void buttonOperation(int src, int dest, int floors, int up, int down){
    vector<int>floorPos(floors+1);
    Floor f;
    queue<Floor>q;

    q.push({src, 0});
    floorPos[src] = 1;

    while(!q.empty()){
        f = q.front();
        q.pop();
        //reached destination
        if(f.val == dest){
            cout<<f.bpush;
            return;
        }
        //upward movement
        int floorUp = f.val + up;
        if(floorUp <= floors && !floorPos[floorUp]){
            floorPos[floorUp] = 1;
            q.push({floorUp, f.bpush+1});
        }
        //downward movement
        int floorDown = f.val - down;
        if(floorDown >= 1 && !floorPos[floorDown]){
            floorPos[floorDown] = 1;
            q.push({floorDown, f.bpush+1});
        }
    }
    //no way to reach
    cout<<"use the stairs";
    return;
}

int main(){
    int src, dest, floors, up, down;
    cin>>floors>>src>>dest>>up>>down;
    buttonOperation(src, dest, floors, up, down);

    return 0;
}
