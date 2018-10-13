#include <iostream>
#include <algorithm>
using namespace std;

struct pin{
    int i,j,direction;
};

int N,ans,si,sj;
int map[100][100];
int wh[11][2][2];
int dir[4][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};
int block[6][4] = {
    {},
    {2,3,1,0},
    {1,3,0,2},
    {3,2,0,1},
    {2,0,3,1},
    {2,3,0,1}
};

bool check(int i,int j){
    return (i>=0 && j>=0 && i<N && j<N) ? true : false;
}

int cal(int si,int sj){
    pin p; int maxcnt = 0;
    for(int d=0; d<4; d++){
        p.i=si;
        p.j=sj;
        p.direction = d;
        int cnt = 0;
        do{
            p.i+=dir[p.direction][0];
            p.j+=dir[p.direction][1];
            int now=map[p.i][p.j];
            if(!check(p.i,p.j)){
                cnt++;
                p.direction=block[5][p.direction];
            }else if(now >=1 && now <=5){
                cnt++;
                p.direction=block[now][p.direction];
            }else if(now>=6 && now<=10){
                if(wh[now][0][0] == p.i && wh[now][0][1]==p.j){
                    p.i=wh[now][1][0];
                    p.j=wh[now][1][1];
                }else{
                    p.i=wh[now][0][0];
                    p.j=wh[now][0][1];
                }
            }
        }while(!(p.i==si && p.j == sj) && map[p.i][p.j]!=-1);
        maxcnt = max(maxcnt,cnt);
    }
    return maxcnt;
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++){
        cin >> N;
        ans = 0;
        for(int i=6; i<=10; i++){
            wh[i][0][0] = -1; wh[i][0][1] = -1; wh[i][1][0] = -1; wh[i][1][1] = -1;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
                if(map[i][j] >5){
                    if(wh[map[i][j]][0][0] == -1){
                        wh[map[i][j]][0][0] = i;
                        wh[map[i][j]][0][1] = j;
                    }else{
                        wh[map[i][j]][1][0] = i;
                        wh[map[i][j]][1][1] = j;
                    }
                }
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j] == 0){
                    ans = max(ans,cal(i,j));
                }
            }
        }
        cout <<"#" << tc << " " << ans << endl;
    }
    return 0;
}

