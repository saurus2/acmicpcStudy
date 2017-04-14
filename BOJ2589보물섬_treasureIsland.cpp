#include <iostream>
#include <queue>
#include <memory.h>
#define mp make_pair
using namespace std;
int ret=0, l, w, check[51][51], x, y, nx, ny, maxR=-9876543, temp[51][51];
int dd[][2] = {{-1,0},{1,0},{0,1},{0,-1}};
//방향 저장
char map[51][51];
queue <pair<int,int>> Q;
//bfs 수행할곳
int bfs(){
    while(!Q.empty()){
        x=Q.front().first; y=Q.front().second;
        Q.pop();
        for(int i=0; i<4; i++){
            nx=x+dd[i][0]; ny=y+dd[i][1];
            //다음 위치 저장
            if(nx<0 || ny<0 || nx>l-1 || ny>w-1 ) continue;
            //이동할 곳이 범위 넘는지 확인
            if(check[nx][ny] != 0) continue;
            //체크할 2차원 배열에 이동가능한 0이 아니면 통과
            check[nx][ny] = check[x][y] + 1;
            //이전의 거리에 1씩 더해서 저장
            Q.push(mp(nx,ny));
        }
    }
    return ret;
}
int main(){
    memset(map,0,sizeof(map));
    memset(temp,0,sizeof(temp));
    cin >> l >> w;
    for(int i=0; i<l; i++){
        getchar();
        for(int j=0; j<w; j++){
            map[i][j] = getchar();
            if(map[i][j] == 'W') temp[i][j] = -1;
            //물이 있는곳은 가지 못하게 체크 배열에 -1 저장
        }
    }
    
    for(int i=0; i<l; i++){
        for(int j=0; j<w; j++){
            memcpy(check,temp,sizeof(temp));
            //이미 저장되어있는 물과 땅 2차원 임시 배열을 체크 배열에 저장
            while(!Q.empty()) Q.pop();
            if(map[i][j] == 'L'){
                // 땅일때만 시작
                Q.push(mp(i,j));
                check[i][j] = 1;
                //출발지를 1로 설정
                bfs();
                //돌아 댕긴다.
                for(int o=0; o<l; o++)
                    for(int p=0; p<w; p++)
                        maxR = max(maxR, check[o][p]);
                //다시한번 다 뒤져서 가장 장거리의 값을 구한다
                //체크하면서 돌아다니기 때문에 현재 자리에서 돌아가는 가능성은 배제 된다.
            }
        }
    }
    cout << maxR-1 << endl;
    return 0;
}
