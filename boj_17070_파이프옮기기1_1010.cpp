#include <iostream>
#include <queue>

using namespace std;
int diyx[3][2]={
    {0,1},
    {1,1},
    {1,0}
};
struct node{
    int y,x,dis;
};
queue <node> que;
int mp[17][17],n,answer;
void input(){
    answer=0;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mp[i][j];
        }
    }
}

void bfs(){
    node stn;
    stn.dis=0;
    stn.y=0;
    stn.x=1;
    que.push(stn);
    while(!que.empty()){
        node curn=que.front();
        que.pop();
        for(int i=0; i<3; i++){
            int ny=curn.y+diyx[i][0];
            int nx=curn.x+diyx[i][1];
            if(curn.dis==0 && i==2) continue;
            if(curn.dis==2 && i==0) continue;
            if(ny<0 || nx<0 || ny>=n || nx>=n || mp[ny][nx]==1) continue;
            if(i==1 && mp[ny-1][nx] ==1) continue;
            if(i==1 && mp[ny][nx-1] ==1) continue;
            if(ny==n-1 && nx==n-1){
                answer++;
                continue;
            }
            node nextn=curn;
            nextn.y=ny;
            nextn.x=nx;
            nextn.dis=i;
            que.push(nextn);
        }
    }
}

int main(){
    input();
    bfs();
    cout << answer << endl;
    return 0;
}

