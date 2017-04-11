#include <iostream>
#include <queue>
#define mp make_pair
#define INF 87654321
using namespace std;
int n,m,maep[1001][1001]={0},chmaep[1001][1001][2]={0},//벽의 상태에따라 움직인 거리를 따로 저장
cnt=1,well=0,mx[4]={-1,1,0,0},my[4]={0,0,-1,1};//방향이동에 따라 4 포인트를 저장
queue<pair<int,pair<int,int>>> que;
void bfs(){
    while(!que.empty()){
        int xt=que.front().second.first, yt=que.front().second.second, wt=que.front().first;
        que.pop();
        for(int i=0; i<4; i++){
            int xt2 = xt+mx[i], yt2 = yt+my[i];
            if(xt2 >= 0 && xt2 < n && yt2 >= 0 && yt2 < m){//범위에서 초과되지 않을때만 움직임
                if(maep[xt2][yt2] == 0 && (chmaep[xt][yt][wt]+1 < chmaep[xt2][yt2][wt])){
                    //벽이 없을때 한칸 전의 값이 이동한 칸의 거리와 비교
                    chmaep[xt2][yt2][wt] = chmaep[xt][yt][wt]+1;
                    que.push(mp(wt,mp(xt2,yt2)));//벽의 상태를 같이 큐에 넣음
                }
                if(maep[xt2][yt2] == 1 && wt == 0 && (chmaep[xt][yt][0]+1 < chmaep[xt2][yt2][1])){
                    //벽이 있을때, 벽을 부수지 않은 상태면 진행
                    chmaep[xt2][yt2][1] = chmaep[xt][yt][0]+1;
                    que.push(mp(1,mp(xt2,yt2)));
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&maep[i][j]);
            for(int k=0; k<2; k++)
                chmaep[i][j][k]=INF;
        }
    }
    chmaep[0][0][0]=1;//처음칸도 포함
    que.push(mp(0,mp(0,0)));
    bfs();
    if(chmaep[n-1][m-1][0] == INF && chmaep[n-1][m-1][1] == INF) cout << -1 << endl;
    //도착지에 도착하지 않을때
    else cout << min(chmaep[n-1][m-1][0],chmaep[n-1][m-1][1]) << endl;
    //도착 했을때 벽을 부순거랑 안부순것의 미니멈
    return 0;
}
