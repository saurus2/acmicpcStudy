#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,mp[9][9],visited[9][9],answer,vcSize;
struct nd{
    int y,x,val;
};
int dixy[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
vector <nd> vc;
void input(){
    cin >> n >> m;
    answer=100;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j]=0;
            int tmp;
            cin >> tmp;
            if(tmp>0 && tmp<6){
                nd nnd;
                nnd.y=i;nnd.x=j;nnd.val=tmp;
                vc.push_back(nnd);
                mp[i][j]=0;
            }
            mp[i][j]=tmp;
        }
    }
    vcSize=(int)vc.size();
}

int mpCnt(){
    int mCnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mp[i][j]==0 && visited[i][j]==0)
                mCnt++;
        }
    }
    return mCnt;
}

void pt(int y,int x,int dis,int er){
    int ny=y;
    int nx=x;
    while(1){
        ny+=dixy[dis][0];
        nx+=dixy[dis][1];
        if(mp[ny][nx]==6 || ny<0 || nx<0 || ny>=n || nx>=m){
            return;
        }
        if(er==1)
            visited[ny][nx]++;
        else if(er==0 && visited[ny][nx]>0)
            visited[ny][nx]--;
    }
}

void dfs(int idx,int cnt){
    if(idx>vcSize){
        return;
    }
    if(cnt == vcSize){
        answer=min(answer,mpCnt());
        return;
    }
    
    if(vc[idx].val==1){
        for(int i=0; i<4; i++){
            pt(vc[idx].y,vc[idx].x,i,1);
            dfs(idx+1,cnt+1);
            pt(vc[idx].y,vc[idx].x,i,0);
        }
    }else if(vc[idx].val==2){
        for(int i=0; i<2; i++){
            pt(vc[idx].y,vc[idx].x,0+i,1);
            pt(vc[idx].y,vc[idx].x,2+i,1);
            dfs(idx+1,cnt+1);
            pt(vc[idx].y,vc[idx].x,0+i,0);
            pt(vc[idx].y,vc[idx].x,2+i,0);
        }
    }else if(vc[idx].val==3){
        for(int i=0; i<4; i++){
            pt(vc[idx].y,vc[idx].x,0+i,1);
            pt(vc[idx].y,vc[idx].x,(1+i)%4,1);
            dfs(idx+1,cnt+1);
            pt(vc[idx].y,vc[idx].x,0+i,0);
            pt(vc[idx].y,vc[idx].x,(1+i)%4,0);
        }
    }else if(vc[idx].val==4){
        for(int i=0; i<4; i++){
            pt(vc[idx].y,vc[idx].x,(0+i)%4,1);
            pt(vc[idx].y,vc[idx].x,(1+i)%4,1);
            pt(vc[idx].y,vc[idx].x,(2+i)%4,1);
            dfs(idx+1,cnt+1);
            pt(vc[idx].y,vc[idx].x,(0+i)%4,0);
            pt(vc[idx].y,vc[idx].x,(1+i)%4,0);
            pt(vc[idx].y,vc[idx].x,(2+i)%4,0);
        }
    }else if(vc[idx].val==5){
        pt(vc[idx].y,vc[idx].x,0,1);
        pt(vc[idx].y,vc[idx].x,1,1);
        pt(vc[idx].y,vc[idx].x,2,1);
        pt(vc[idx].y,vc[idx].x,3,1);
        dfs(idx+1,cnt+1);
    }
}


int main(){
    input();
    dfs(0,0);
    cout << answer;
}

