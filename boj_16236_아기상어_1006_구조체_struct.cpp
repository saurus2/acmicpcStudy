#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int n_dist,n_y,n_x;
};

vector <node> fish2;
queue <node> shark2;

bool comp(const node &a,const node &b){
    if(a.n_dist<b.n_dist){
        return true;
    }else if(a.n_dist==b.n_dist){
        if(a.n_y<b.n_y){
            return true;
        }else if(a.n_y==b.n_y){
            if(a.n_x<b.n_x){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}


int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int arr[21][21];
int visited[21][21];
int n,sy,sx,resTime,cCnt,cLev;
void bfs(){
    while(1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        while(!shark2.empty()){
            node cur_shark=shark2.front();
            int cDist=shark2.front().n_dist;
            int cy=shark2.front().n_y;
            int cx=shark2.front().n_x;
            
            shark2.pop();
            for(int i=0;i<4;i++){
                int ny=cy+dy[i];
                int nx=cx+dx[i];
                int nDist=cDist+1;
                if(ny<0||nx<0||ny>=n||nx>=n) continue;
                if(visited[ny][nx]==1) continue;
                visited[ny][nx]=1;
                if(cLev<arr[ny][nx]) continue;
                if(arr[ny][nx]>0&&cLev>arr[ny][nx]){
                    node cur_fish;
                    cur_fish.n_dist=nDist;
                    cur_fish.n_y=ny;
                    cur_fish.n_x=nx;
                    fish2.push_back(cur_fish);
                }
                cur_shark.n_dist=nDist;
                cur_shark.n_y=ny;
                cur_shark.n_x=nx;
                shark2.push(cur_shark);
            }
        }
        if(fish2.empty()) return;
        sort(fish2.begin(),fish2.end(),comp);
        resTime+=fish2.begin()->n_dist;
        int yy=fish2.begin()->n_y;
        int xx=fish2.begin()->n_x;
        arr[yy][xx]=0;
        cCnt++;
        if(cLev<=cCnt){
            cLev++;
            cCnt=0;
        }
        node next_shark;
        next_shark.n_dist=0;
        next_shark.n_y=fish2.begin()->n_y;
        next_shark.n_x=fish2.begin()->n_x;
        shark2.push(next_shark);
        fish2.clear();
    }
}
int main(){
    cLev=2;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==9){
                sy=i;sx=j;
                arr[i][j]=0;
            }
        }
    }
    node cur_node;
    cur_node.n_dist=0;
    cur_node.n_y=sy;
    cur_node.n_x=sx;
    shark2.push(cur_node);
    bfs();
    printf("%d",resTime);
}

