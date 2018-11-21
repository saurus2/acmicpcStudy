#include <cstdio>
#include <deque>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <utility>
using namespace std;
pair <int ,int > pr;
deque < pair < int, int > > que;
int M, N;
int mp[1001][1001]={0,};
int ck[1001][1001]={0,};
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int main(){
    int answer = 0;
    scanf("%d %d", &M, &N);
    que.clear();
    memset(ck,0,sizeof(ck));
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &mp[i][j]);
            if(mp[i][j] == 0 && i == 0)
                que.push_back({i,j});
        }
    }
    
    while(!que.empty()){
        int ny = que.front().first;
        int nx = que.front().second;
        if(ny == M-1){
            answer = 1;
            break;
        }
        //ck[nny][nnx] = 1; // 체크해야할 부분을 처음 짤때 생각을 하지 못해서 계속 무한 반복 했다.
        que.pop_front();
        
        for(int i=0; i<4; i++){
            int nny = ny + dy[i];
            int nnx = nx + dx[i];
            if(nny < 0 || nnx < 0 || nny >= M || nnx >= N || ck[nny][nnx] == 1 || mp[nny][nnx] == 1) continue;
            ck[nny][nnx] = 1;
            que.push_back({nny, nnx});
        }
    }
    if(answer == 1)
        printf("YES\n");
    else
        printf("NO\n");
}

