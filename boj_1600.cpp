#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair < pair < int, int >, pair < int, int > > piiii;
queue <piiii> que;
int K, W, H, arr[201][201], visited[201][201][31];
int sy=0,sx=0,dy,dx,answer = 1000000000;
int mky[4] = {-1,0,1,0};
int mkx[4] = {0,1,0,-1};
int hry[8] = {-2,-1,1,2, 2, 1,-1,-2};
int hrx[8] = {1,  2,2,1,-1,-2,-2,-1};
bool over(int y,int x,int cnt){
    if(y < 0 || x < 0 || y >= H || x >= W ||  arr[y][x] == 1 || visited[y][x][cnt] == 1) return true;
    return false;
}
int main(){
    scanf("%d", &K);
    scanf("%d %d", &W, &H);
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    dy=H-1;
    dx=W-1;
    for(int i=0; i<31; i++)
        visited[0][0][i] = 1;
    
    que.push({{K,0},{sy,sx}});
    while(!que.empty()){
        int ck = que.front().first.first;
        int ccnt = que.front().first.second;
        int cy = que.front().second.first;
        int cx = que.front().second.second;
        que.pop();
        
        if(ck > 0){
            for(int i=0; i<8; i++){
                int nk = ck - 1;
                int ncnt = ccnt + 1;
                int ny = cy + hry[i];
                int nx = cx + hrx[i];
                if(ny == dy && nx == dx){
                    printf("%d\n", ncnt);
                    return 0;
                }
                if(over(ny, nx, nk)) continue;
                visited[ny][nx][nk] = 1;
                que.push({{nk,ncnt},{ny,nx}});
            }
        }
        
        for(int i=0; i<4; i++){
            int nk2 = ck;
            int ncnt2 = ccnt + 1;
            int ny2 = cy + mky[i];
            int nx2 = cx + mkx[i];
            if(ny2 == dy && nx2 == dx){
                if(ny2 == dy && nx2 == dx){
                    printf("%d\n", ncnt2);
                    return 0;
                }
            }
            if(over(ny2,nx2,nk2)) continue;
            visited[ny2][nx2][nk2] = 1;
            que.push({{nk2,ncnt2},{ny2,nx2}});
        }
    }
    if(answer == 1000000000)
        printf("-1");
    else
        printf("%d", answer);
    return 0;
}

