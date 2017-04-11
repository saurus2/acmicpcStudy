#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    char map[12][6];//맵을 저장받을 2차원배열
    bool visited[12][6];//방문한곳을 확인할 2-배열
    char c;
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            cin >> c;
            map[i][j] = c;
        }
    }
    int xoff[4] = {-1,1,0,0};
    int yoff[4] = {0,0,-1,1};
    
    int result = 0;
    while(1){
        bool chain = false;//연결되어있는 뿌요 확인
        vector<int> Q;//bfs 용 큐
        
        for(int i=0; i<12; i++)
            for(int j=0; j<6; j++)
                if(map[i][j] != '.'){
                    Q.push_back(i*6+j);//큐에 배열의 가로세로 번호를 합쳐서 저장
                    memset(visited, 0, sizeof(visited));//매번 초기화
                    for(int k=0; k<Q.size(); k++){
                        int r = Q[k]/6;
                        int c = Q[k]%6;
                        if(visited[r][c]) continue;//방문한적이 있으면 통과
                        visited[r][c] = true;//체크먼저 하고 시작
                        for(int d=0; d<4; d++){
                            int rn = r+yoff[d];
                            int cn = c+xoff[d];
                            if(r<0 || c<0 || r>=12 || c>=6)continue;//범위확인
                            if(visited[rn][cn]) continue;//확인할 뿌요 위치가 방문했었던 곳인지 확인
                            if(map[rn][cn] != map[r][c]) continue;//같은 뿌요일때만 이동
                            Q.push_back(rn*6+cn);//같은 뿌요를 큐에 삽입
                        }
                    }
                    if(Q.size()>=4){//인접한 뿌요가 4개 이상 큐에 저장될때
                        for(int i=0; i<Q.size(); i++){
                            map[Q[i]/6][Q[i]%6] = '.';//모두 제거
                        }
                        chain = true;//뿌요를 터뜨렸기 때문에 끝내지 않고 뿌요들 정리
                    }
                    Q.clear();//큐에 터뜨릴 뿌요들 제거
                }
        
        if(!chain)break;//연쇄된 뿌요가 없을때 끝
        result++;
        char newMap[12][6];
        memset(newMap, '.', sizeof(newMap));
        for(int c=0; c<6; c++){
            int r1 = 11;
            for(int r=11; r>=0; r--){
                if(map[r][c] != '.'){//뿌요가 터진곳이면 위에서 아래로 바꿔줌
                    newMap[r1--][c] = map[r][c];
                }
            }
        }
        memcpy(map, newMap, sizeof(map));//터진뿌요를 정리한 맵을 원래맵에 저장후 반복
    }
    printf("%d\n", result);
}
