#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#define mp make_pair
using namespace std;
int map[50][50];
bool visit[50][50];
int sx,sy,ex,ey;
char t;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int main(){
    int r,c;
    char t;
    scanf("%d %d\n", &r, &c);
    memset(map,10000,sizeof(map));
    queue<pair<int,int>> que;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> t;
            if(t == 'D'){
                map[i][j] = 10000;
                ey = i;
                ex = j;
            }else if(t == 'S'){
                map[i][j] = 10000;
                sy = i;
                sx = j;
            }else if(t == 'X'){
                map[i][j] = 0;
                visit[i][j] = 1;
            }else if(t == '*'){
                que.push(mp(i,j));
            }
        }
    }
    visit[sy][sx] = visit[ey][ex] = 1;
    for(int turn = 0; !que.empty(); turn++){
        //물을 큐에 넣고 방문한 곳을 체크해나가면서, 큐에 들어간 모든 물이 번지는 시간을
        //turn으로 하여 0 부터 저장하며 늘려간다.
        //D가 움직일때 turn의 값을 비교하여 못가는 범위를 제한한다.
        long long len = que.size();
        for(int i=0; i<len; i++){
            pair<int, int> here = que.front();
            que.pop();
            int x = here.second, y = here.first;
            if(y<0 || x<0 || y>=r || x>=c|| visit[y][x]) continue;
            visit[y][x] = 1;
            map[y][x] = min(map[y][x], turn);
            for(int i=0; i<4; i++){
                que.push(mp(y+dy[i],x+dx[i]));
            }
        }
    }
    memset(visit,0,sizeof(visit));
    que.push(mp(sy,sx));
    for(int turn = 0; !que.empty(); turn++){
        long long len = que.size();
        for(int i=0; i<len; i++){
            pair<int,int> here = que.front();
            que.pop();
            int x = here.second, y=here.first;
            if(y<0 || x<0 || y>=r || x>=c || map[y][x] <= turn || visit[y][x]) continue;
            //초마다 물이 채워진 값의 기록으로 갈수 있는지 없는지 정한다.
            //최소로 도착해야하기 때문에 들렸던 곳은 다시 가지 않아도 된다.
            visit[y][x] = 1;
            if(y==ey && x==ex){
                cout << turn << endl;
                return 0;
            }
            for(int i=0; i<4; i++){
                que.push(mp(y+dy[i],x+dx[i]));
            }
        }
    }
    cout << "KAKTUS" << endl;
}
