#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
typedef pair<int,int> P;
queue <P> Q;
int map[301][301]={0}, py[301][301]={0}, chk[301][301]={0},zcnt=0;
int d[][2]={{0,1},{1,0},{-1,0},{0,-1}};
int main(){
    int n,m,yCnt=0,seCnt=0,res=0;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || i == n-1 || j == 0 || j == m-1) map[i][j] = 0;
            cin >> map[i][j];
        }
    }
    while(1){
        memcpy(py,map,sizeof(map));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(py[i][j] > 0){
                    int ct = 0;
                    for(int k=0; k<4; k++){
                        int ny = i+d[k][1], nx = j+d[k][0];
                        if(py[ny][nx]==0)ct++;
                        //상하좌우 0인 부분을 확인하여 녹는 수를 증가시킴
                    }
                    map[i][j] = map[i][j] - ct < 0 ? 0 : map[i][j] - ct;
                    //0이하로 내려가게 된다면 0으로 바꿈
                }
            }
        }
        yCnt++;
        zcnt=0;
        //빙하가 녹았는지 확인하기
        seCnt=0;
        memset(chk,0,sizeof(chk));
        //빙하 분리된 것 확인용 배열
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == 0) zcnt++;
                //바다 갯수 세기
                if(map[i][j]>0 && chk[i][j] != 1){
                    Q.push(P(i,j));
                    chk[i][j] = 1;
                    while(!Q.empty()){
                        //연결된 빙산 갯수 해주는 bfs
                        int y=Q.front().first, x=Q.front().second;
                        Q.pop();
                        for(int i=0; i<4; i++){
                            int ny = y+d[i][1], nx = x+d[i][0];
                            if(map[ny][nx]>0 && chk[ny][nx] != 1){
                                chk[ny][nx]=1;
                                Q.push(P(ny,nx));
                            }
                        }
                    }
                    seCnt++;
                    //연결되 빙산 갯수
                }
            }
        }
        if(seCnt>=2 && res == 0){
            //분리된 빙산 갯수가 2개 이상이면 끝내고 연도 출력
            cout << yCnt;
            res = 1;
            break;
        }else if(zcnt == n*m){
            break;
        }
    }
    if(res == 0)
        cout << "0" << endl;
    return 0;
}
