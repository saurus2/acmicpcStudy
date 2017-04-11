#include <iostream>
#include <queue>
#define mp make_pair
using namespace std;
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,1,-1,1,-1};
//대각선, 상하좌우 8방향
int main(){
    while(1){
        int w,h,som[51][51]={0},check[51][51]={0},cnt=0;
        //매 케이스마다 초기화, 갯수도 초기화
        queue <pair<int,int>> Q;
        //bfs할 큐 생성
        while(!Q.empty())Q.pop();
        //큐 초기화
        cin >> w >> h;
        //너비와 높이 입력
        if(w==0 && h ==0) break;
        //00입력시 끝
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> som[i][j];
                check[i][j] = !som[i][j];
                //물에 관한것을 그냥 방문한 범위로 입력
            }
        }
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(check[i][j] == 1) continue;
                //방문한 곳과 물은 검사안함
                Q.push(mp(i,j));
                //땅만 집어넣기
                while(!Q.empty()){
                    int cx = Q.front().second, cy = Q.front().first;
                    //입력한 땅을 가져옴
                    Q.pop();
                    for(int i=0; i<8; i++){
                        int nx = cx + dx[i], ny = cy + dy[i];
                        //8개의 방향 조사
                        if(nx < 0 || ny < 0 || nx >= w || ny >= h || check[ny][nx]) continue;
                        //방문 & 물 & 범위 초과서 뛰어넘기
                        check[ny][nx]=1;
                        Q.push(mp(ny,nx));
                        //방문한거 체크후 큐에 삽입
                    }
                }
                cnt++;
                //큐하나가 끝나면 이어진 땅은 확인한것 +1
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
