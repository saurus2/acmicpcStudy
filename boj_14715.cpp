#include <iostream>
#include <queue>
#include <cstdio>
#include <utility>
#include <memory.h>
using namespace std;
int mp[251][251],visit[251][251];
int M,N;
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};
queue < pair < int, int > > que;
int main(){
    scanf("%d %d", &M,&N);
    memset(visit,0,sizeof(visit));
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &mp[i][j]);
        }
    }
    int ncnt = 0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            
            if(mp[i][j] == 0) continue;
            if(visit[i][j] == 1) continue;
            
            visit[i][j] = 1;
            que.push({i,j});
            ncnt++;
            
            while(!que.empty()){
                int cy = que.front().first;
                int cx = que.front().second;
                que.pop();
                
                for(int i=0; i<8; i++){
                    int ny = cy + dy[i];
                    int nx = cx + dx[i];
                    
                    if(ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
                    if(mp[ny][nx] == 0) continue;
                    if(visit[ny][nx] == 1) continue;
                    
                    visit[ny][nx] = 1;
                    que.push({ny,nx});
                }
            }
        }
    }
    printf("%d", ncnt);
    return 0;
}

