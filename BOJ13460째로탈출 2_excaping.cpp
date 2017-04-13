#include <iostream>
#include <string>
#include <queue>
#include <memory.h>
#define mp make_pair
using namespace std;
int n,m,rx,ry,bx,by,dex,dey,ret;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
//하상우좌 공 굴릴 좌표를 미리 저장
char jje[11][11]={0},chk[11][11][11][11]={0};
//지도랑 움직인곳을 체크할 곳 저장, R와 B공의 각자 위치 한번에저장
struct ball{
    int crx;
    int cry;
    int cbx;
    int cby;
};
//큐에 넣고 bfs할때 두개의 공좌표 모두 넣기
struct ball;
queue<ball> order;
int se(){
    struct ball s;
    s.crx = rx; s.cry = ry;
    s.cbx = bx; s.cby = by;
    chk[s.crx][s.cry][s.cbx][s.cby] = 1;
    order.push(s);
    //첫 공들의 위치 큐에 넣기
    ret = 0;
    while(!order.empty()){
        //큐가 바닥날때 끝
        auto len = order.size();
        for(auto i=0; i<len; i++){
            //bfs시 한 level당 움직임 +1
            s = order.front();
            order.pop();
            if(jje[s.crx][s.cry] == 'O' && jje[s.cbx][s.cby] != 'O')
                //빨간공은 도착 , 파란공은 도착이 아닐때만 반환
                return ret;
            for(int i=0; i<4; i++){
                int nrx = s.crx, nry = s.cry, nbx = s.cbx, nby = s.cby;
                while(jje[nrx + dx[i]][nry + dy[i]] != '#' &&
                      jje[nrx][nry] != 'O'){
                    //벽에 도착하지 않고, 도착이 아니면 빨간공 좌표 증가
                    nrx += dx[i]; nry += dy[i];
                }
                while(jje[nbx + dx[i]][nby + dy[i]] != '#' &&
                      jje[nbx][nby] != 'O'){
                    //벽에 도착하지 않고, 도착이 아니면 파란공 좌표 증가
                    nbx += dx[i]; nby += dy[i];
                }
                
                if(nrx == nbx && nry == nby){
                    //파란공 빨간공 겹칠때.
                    if(jje[nrx][nry] == 'O') continue;
                    //공이 모두 원에 들어갔을때
                    if(abs(nrx - s.crx) + abs(nry - s.cry) < abs(nbx - s.cbx) + abs(nby - s.cby)){
                        //좌표를 가지고 좌표 절대값이 더 큰 공색을 위에서 더 해준 좌표만큼 빼줌
                        nbx -= dx[i];
                        nby -= dy[i];
                    }else{
                        //위와 동이
                        nrx -= dx[i];
                        nry -= dy[i];
                    }
                }
                if(chk[nrx][nry][nbx][nby])continue;
                //방문한 곳이면 취소
                order.push({nrx,nry,nbx,nby});
                //bfs를 위해 큐에 삽입
                chk[nrx][nry][nbx][nby]=1;
            }
        }
        if(ret == 10)
            //10개 이내이니 10이 되면 -1 리턴
            return -1;
        ret++;
        //        갯수 하나씩 증가
    }
    return -1;
}
int main(){
    string sen;
    cin >> n >> m;
    int k = 0;
    for(int i=0; i<n; i++){
        cin >> sen;
        k=0;
        for(int j=0; j<m; j++){
            jje[i][j] = sen[k++];
            if(jje[i][j] == 'R') {
                rx=i;ry=j;
            }
            if(jje[i][j] == 'B') {
                bx=i;by=j;
            }
        }
    }
    cout << se();
    return 0;
}
