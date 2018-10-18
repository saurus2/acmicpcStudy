#include <iostream>
#include <queue>
using namespace std;

int n,m,by,bx,ry,rx;
int ch[11][11][11][11];
int dis[4][2]={
    {-1,0},
    {0,-1},
    {1,0},
    {0,1}
};
struct nd{
    int cnt,ry,rx,by,bx;
};
queue <nd> que;
char map[12][12];

int main(){
    int ans = 0;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                ry = i;
                rx = j;
            }
            if(map[i][j] == 'B'){
                by = i;
                bx = j;
            }
        }
    }
    ch[ry][rx][by][bx] = 1;
    nd p1;
    p1.ry = ry; p1.rx = rx; p1.by = by; p1.bx = bx; p1.cnt = 0;
    que.push(p1);
    int exit = 1;
    while(!que.empty()){
        nd now = que.front();
        que.pop();
        for(int i=0; i<4; i++){
            exit = 0;
            int nry = now.ry;
            int nrx = now.rx;
            int nby = now.by;
            int nbx = now.bx;
            int cr = 0;
            int cb = 0;
            
            while(map[nry + dis[i][0]][nrx + dis[i][1]] != '#' && map[nry][nrx] != 'O'){
                nry += dis[i][0];
                nrx += dis[i][1];
                cr++;
            }
            
            while(map[nby + dis[i][0]][nbx + dis[i][1]] != '#' && map[nby][nbx] != 'O'){
                nby += dis[i][0];
                nbx += dis[i][1];
                cb++;
            }
            
            if(nry == nby && nrx == nbx){
                if(map[nry][nrx] == 'O') continue;
                if(cr < cb){
                    nby -= dis[i][0];
                    nbx -= dis[i][1];
                }else{
                    nry -= dis[i][0];
                    nrx -= dis[i][1];
                }
            }
            
            if(map[nby][nbx] == 'O') continue;
            if(map[nry][nrx] == 'O'){
                ans = now.cnt;
                exit = 1;
                break;
            }
            if(ch[nry][nrx][nby][nbx]==1) continue;
            if(now.cnt < 9){
                ch[nry][nrx][nby][nbx] = 1;
                nd pt;
                pt.ry = nry; pt.rx = nrx; pt.by = nby; pt.bx = nbx;
                pt.cnt = now.cnt + 1;
                que.push(pt);
            }
        }
        if(exit ==1)
            break;
    }
    if(exit==1)
        cout << ans+1 << endl;
    else
        cout << "-1" << endl;
}

