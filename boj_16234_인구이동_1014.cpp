#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int mp[51][51],visited[51][51],n,l,r,answer;
struct node{
    int y,x,val,lb;
};
int dis[4][2]={
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
};
queue <node> que;
vector <node> vc;
void input(){
    answer=0;
    for(int i=0; i<51; i++)
        for(int j=0; j<51; j++)
            visited[i][j]=0;
    cin >> n >> l >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mp[i][j];
        }
    }
}
void pt(){
    cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
}
int func(){
    int cnt = 1;
    int f=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]==1) continue;
            int sum=0;
            node cn;
            cn.y=i; cn.x=j; cn.val=mp[i][j]; cn.lb=cnt;
            sum+=cn.val;
            que.push(cn);
            visited[i][j]=1;
            vc.push_back(cn);
            while(!que.empty()){
                node curn=que.front();
                que.pop();
                for(int i=0; i<4; i++){
                    node nexn;
                    nexn.y=curn.y+dis[i][0];
                    nexn.x=curn.x+dis[i][1];
                    if(nexn.y>=n || nexn.x>=n || nexn.y<0 || nexn.x<0) continue;
                    if(visited[nexn.y][nexn.x]==1) continue;
                    nexn.val=mp[nexn.y][nexn.x];
                    if(abs(nexn.val-curn.val)>=l && abs(nexn.val-curn.val)<=r){
                        visited[nexn.y][nexn.x]=1;
                        nexn.lb=cnt;
                        vc.push_back(nexn);
                        que.push(nexn);
                        sum+=nexn.val;
                        f=1;
                    }
                }
            }
            if(!vc.empty()){
                int vcSize=vc.size();
                sum/=vcSize;
                for(int k=0; k<vcSize; k++){
                    mp[vc[k].y][vc[k].x]=sum;
                }
            }
            vc.clear();
            //pt();
        }
    }
    if(f==1) return 1;
    return 0;
}
int main(){
    input();
    while(1){
        if(func()==1){
            answer++;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    visited[i][j]=0;
                }
            }
        }else{
            break;
        }
    }
    cout << answer << endl;
}

