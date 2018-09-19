#include <iostream>
using namespace std;

int R,C,sy,sx,sdis;
int mp[51][51];
int ck[51][51];
int cnt=0;
int dis[4][2]={
    {-1,0},//북
    {0,1},//동
    {1,0},//남
    {0,-1}//서
};

void dfs(int y,int x,int ndis){
//    for(int i=0; i<R; i++){
//        for(int j=0; j<C; j++){
//            printf("%3d",ck[i][j]);
//        }
//        cout << endl;
//    }
//    cout << endl;
    int tmpdis = ndis;
    for(int i=0; i<4; i++){//2-2.
        
        
        tmpdis = ( tmpdis + 3 ) % 4;
        int tmpr = y + dis[tmpdis][0];
        int tmpc = x + dis[tmpdis][1];
        
        if(tmpr < 0 || tmpc < 0 || tmpr >= R || tmpc >= C || mp[tmpr][tmpc]==1)
            continue;
        
        
        if(mp[tmpr][tmpc] == 0){ //2-1.
            cnt++;
            mp[tmpr][tmpc] = 2;
            ck[tmpr][tmpc] = cnt;
            dfs(tmpr,tmpc,tmpdis);
            return;
        }
    }
    tmpdis = ( ndis + 2 ) % 4;
    int ty = y + dis[tmpdis][0];
    int tx = x + dis[tmpdis][1];
    if(mp[ty][tx] == 1)
        return;
    else{
//        cout <<endl;
//        cout << " 후진 : " << ndis << endl;
//        for(int i=0; i<R; i++){
//            for(int j=0; j<C; j++){
//                if(i==ty && j==tx){
//                    printf(" -1");
//                }else{
//                    printf("  0");
//                }
//            }
//            cout << endl;
//        }
//        cout << endl;
        dfs(ty,tx,ndis);
    }
}


int main(){
    cin >> R >> C;
    cin >> sy >> sx >> sdis;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> mp[i][j];
            if(mp[i][j] == 1)
                ck[i][j] = 2;
        }
    }
    if(mp[sy][sx] == 0){
        mp[sy][sx] = 2;
        ck[sy][sx] = 1;
        cnt = 1;
    }else{
        cout << "" << endl;
        return 0;
    }
    
    dfs(sy,sx,sdis);
    cout << cnt;
    
    
}

