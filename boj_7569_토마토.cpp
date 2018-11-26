#include <iostream>
#include <deque>
#include <utility>
#include <memory.h>
using namespace std;
int M,N,H,tomato;
int box[101][101][101];
int visited[101][101][101];
deque < pair< int , pair < int, int > > > que;
int dz[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,0,-1,0};
int dx[6] = {0,0,0,1,0,-1};
int main(){
    tomato = 0;
    scanf("%d %d %d", &M, &N, &H);
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                scanf("%d", &box[i][j][k]);
                if(box[i][j][k] == 1){
                    que.push_back({i , {j, k}});
                    visited[i][j][k] = 1;
                }
                if(box[i][j][k] == 0){
                    tomato++;
                }
            }
        }
    }
    int ti=0;
    int cnt=0;
    while(!que.empty()){
        int queSize = (int)que.size();
        //        printf("\n time : %d \n", ti);
        while(queSize--){
            int cz = que.front().first;
            int cy = que.front().second.first;
            int cx = que.front().second.second;
            que.pop_front();
            for(int i=0; i<6; i++){
                int nz = cz + dz[i];
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                
                if(nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M) continue;
                if(visited[nz][ny][nx] == 1) continue;
                if(box[nz][ny][nx] == -1 || box[nz][ny][nx] == 1) continue;
                visited[nz][ny][nx] = 1;
                
                //                for(int j=0; j<H; j++){
                //                    printf("\n");
                //                    for(int k=0; k<N; k++){
                //                        for(int l=0; l<M; l++){
                //                            printf("%d ", visited[j][k][l]);
                //                        }
                //                        printf("\n");
                //                    }
                //                }
                cnt++;
                que.push_back({nz, {ny, nx}});
            }
        }
        ti++;
    }
    
    if(cnt == tomato){
        printf("%d\n", ti-1);
    }else if(tomato == 0){
        printf("0\n");
    }else{
        printf("-1\n");
    }
    
    return 0;
}



