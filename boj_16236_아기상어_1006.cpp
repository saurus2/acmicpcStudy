#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,mp[21][21],cy,cx,cfSize,eatCnt,visited[21][21],answer=0;
int diyx[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
struct fn{
    int fy,fx,fTime;
};
queue <fn> que;
void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int tmp;
            cin >> tmp;
            if(tmp==9){
                cfSize=2;
                cy=i;
                cx=j;
                eatCnt=0;
                answer=0;
            }else{
                mp[i][j]=tmp;
            }
        }
    }
}

int bfs(){
    for(int i=0; i<21; i++)
        for(int j=0; j<21; j++)
            visited[i][j]=0;
    int curTime=1000000000;
    int curY=0;
    int curX=0;
    while(!que.empty()){
        que.pop();
    }
    fn stfn;
    stfn.fy=cy;
    stfn.fx=cx;
    stfn.fTime=0;
    que.push(stfn);
    while(!que.empty()){
        fn curFn=que.front();
        que.pop();
        for(int i=0; i<4; i++){
            int nextFy=curFn.fy+diyx[i][0];
            int nextFx=curFn.fx+diyx[i][1];
            int nextFTime=curFn.fTime+1;
            if(nextFy<0 || nextFx<0 || nextFy>=n || nextFx>=n) continue;
            if(mp[nextFy][nextFx]>cfSize) continue;
            if(visited[nextFy][nextFx]==1) continue;
            visited[nextFy][nextFx]=1;
            if(mp[nextFy][nextFx]<cfSize && mp[nextFy][nextFx] > 0){
                if(curTime>nextFTime){
                    curTime=nextFTime;
                    curY=nextFy;
                    curX=nextFx;
                }else if(curTime==nextFTime){
                    if(nextFy<curY){
                        curTime=nextFTime;
                        curY=nextFy;
                        curX=nextFx;
                    }else if(nextFy==curY){
                        if(nextFx<curX){
                            curTime=nextFTime;
                            curY=nextFy;
                            curX=nextFx;
                        }
                    }
                }
            }
            fn nextFn;
            nextFn.fTime = nextFTime;
            nextFn.fy=nextFy;
            nextFn.fx=nextFx;
            que.push(nextFn);
        }
    }
    if(curTime!=1000000000){
        cy=curY;
        cx=curX;
        mp[cy][cx]=0;
        eatCnt++;
        if(eatCnt==cfSize){
            cfSize++;
            eatCnt=0;
        }
        answer+=curTime;
        return 1;
    }
    return 0;
}
int main(){
    input();
    while(1){
        int f=bfs();
        if(f==0){
            cout << answer << endl;
            return 0;
        }
    }
}

