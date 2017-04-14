#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct LINE{
    int x1,y1,x2,y2;
    LINE(){};
    LINE(int _x1, int _y1, int _x2, int _y2) :
    x1(min(_x1, _x2)), y1(min(_y1, _y2)),
    x2(max(_x1, _x2)), y2(max(_y1, _y2)){};
    bool is_cross(LINE L){
        //라인이 겹치는지 확인
        if(x2 < L.x1 || L.x2 < x1) return false;
        if(y2 < L.y1 || L.y2 < y1) return false;
        
        return true;
    }
};

int main(){
    int DIR[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    int L, N;
    scanf("%d %d", &L, &N);
    
    LINE line[1005] = {LINE(-L -1, L + 1, L + 1, L + 1),
        LINE(L + 1, -L - 1, L + 1, L + 1),
        LINE(-L - 1, -L - 1, L + 1, -L - 1),
        LINE(-L - 1, -L -1, -L - 1, L + 1)};
    //테두리 라인을 입력받는다.
    
    int limit_i = N + 5, dir = 0;
    //테두리 이후부터 라인 저장
    long long int t = 0, cur_x = 0, cur_y = 0, ans = 0;
    
    for(int i = 4; i < limit_i; i++){
        int add_t; char d;
        
        if(i == N + 4) {
            //명령의 마지막 방향은 그대로 직진한다. 범위를 넘어갈 때까지
            add_t = 2 * L + 1;
            d = 0;
            //마지막에 방향이 바뀌어도 영향을 받지 않음
        }else
            scanf("%d %c", &add_t, &d);
        //마지막이 아니라면 시간초와 방향을 받음
        
        if (ans) continue;
        
        long long int next_x = cur_x + DIR[dir][0] * add_t;
        long long int next_y = cur_y + DIR[dir][1] * add_t;
        // 시간만큼 이동 후의 좌표
        line[i] = LINE(cur_x, cur_y, next_x, next_y);
        //라인에 추가
        int limit_j = (i == 4 ? 4 : i - 1);
        //처음일때는 4 아니면 -1 해줌, 처음에 테두리 4개를 넣었기 때문
        for (int j= 0; j<limit_j; j++)
            //라인의 갯수만큼 반복
            if(line[i].is_cross(line[j])){
                //라인이 겹치는지 확인, 겹치면
                long long int crash_t = 0;
                if(dir == 0 || dir == 2) crash_t = t +
                    abs(line[j].x1 - cur_x);
                //수직으로 움직일때 x 차이
                else crash_t = t + abs(line[j].y1 - cur_y);
                //수평일때 y차이
                
                if(ans) ans = min(ans, crash_t);
                //선에 부딛힐때 작은 값을 저장
                else ans = crash_t;
                //선에 부딛히는게 처음이면 그냥 저장
            }
        
        t += add_t;
        //움직인 칸만큼 시간에 추가
        cur_x = next_x; cur_y = next_y;
        //이동 후 현재 위치 저장
        if ( d == 'R' ) dir = (dir + 3) % 4;
        //오른쪽으로 꺾으면 방향 전환
        else dir = (dir + 1) % 4;
        //왼쪽으로 꺾을때 장향 전환
    }
    
    printf("%lld\n", ans);
    return 0;
}
