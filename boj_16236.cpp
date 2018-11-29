#include <iostream>
#include <utility>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int mp[21][21]={0,}, level = 2, answer = 0, eatCnt = 0, N, bx, by, visit[21][21] ={0,};
typedef pair < int , pair < int , int > > pii;
queue < pii > que;
vector < pii > shark;

bool checkOver(int y, int x){
    if(y < 0 || x < 0 || y >= N || x >= N) return true;
    return false;
}

void findShark(){
    while(1){
        while(!que.empty()){
            int cnt = que.front().first;
            int cy = que.front().second.first;
            int cx = que.front().second.second;
            que.pop();
            
            for(int i=0; i<4; i++){
                int ncnt = cnt+1;
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                
                if(checkOver(ny,nx)) continue;
                if(visit[ny][nx] == 1) continue;
                visit[ny][nx] = 1;
                if(mp[ny][nx] > level) continue;
                else if(mp[ny][nx] > 0 && mp[ny][nx] < level){
                    shark.push_back({ncnt, {ny, nx}});
                    continue;
                }
                que.push({ncnt, {ny, nx}});
            }
        }
        sort(shark.begin(), shark.end());
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                visit[i][j] = 0;
        
        if(!shark.empty()){
            by = shark.at(0).second.first;
            bx = shark.at(0).second.second;
            answer = shark.at(0).first;
            eatCnt += 1;
            if(eatCnt >= level){
                level += 1;
                eatCnt = 0;
            }
            que.push({answer, {by, bx}});
            mp[by][bx] = 0;
            shark.clear();
        }else{
            printf("%d", answer);
            break;
        }
    }
    return;
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &mp[i][j]);
            if(mp[i][j] == 9){
                by = i; bx = j;
                mp[i][j] = 0;
            }
        }
    }
    
    que.push({0, {by, bx}});
    findShark();
    
//    for(int i=0; i<(int)shark.size(); i++){
//        printf("shark val : %d  cnt : %d : Y : %d X : %d\n", mp[shark.at(i).second.first][shark.at(i).second.second], shark.at(i).first, shark.at(i).second.first, shark.at(i).second.second);
//    }
    return 0;
}


