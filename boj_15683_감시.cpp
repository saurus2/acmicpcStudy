#include <iostream>
#include <deque>
using namespace std;
int mp[9][9];
int ck[9][9]={0,};
int ans = 999999999;
int N,M;
int dis[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

struct node{
    int y,  x, dis;
};

deque <node> que;

void paint(int y,int x,int d,bool f){
    int ny = y + dis[d][0];
    int nx = x + dis[d][1];
    if(ny < 0 || nx < 0 || ny > N || nx > M)
        return;
    if(f == 0 && mp[ny][nx] != 6){
        ck[ny][nx]++;
        paint(ny,nx,d,f);
    }else if(f == 1 && ck[ny][nx] != 0){
        ck[ny][nx]--;
        paint(ny,nx,d,f);
    }else {
        return;
    }
}

void dfs(int no,int idx,int cnt){
    if(cnt == (int)que.size()){
        ///
//        cout << endl;
//        for(int i=0; i<N; i++){
//            for(int j=0; j<M; j++){
//                cout << " " << ck[i][j];
//            }
//            cout << endl;
//        }
//        cout << endl;
        ///
        int tmpCnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(mp[i][j] == 0 && ck[i][j] == 0)
                    tmpCnt++;
            }
        }
        if(ans > tmpCnt)
            ans = tmpCnt;
        return;
    }
    int tmp_y = que[idx].y;
    int tmp_x = que[idx].x;
    int tmp_no = que[idx].dis;
    
    if(tmp_no == 1){
        for(int i=0; i<4; i++){
            paint(tmp_y,tmp_x,i,0);
            dfs(tmp_no,idx+1,cnt+1);
            paint(tmp_y,tmp_x,i,1);
//            cout << ":: " << endl;
//            for(int i=0; i<N; i++){
//                for(int j=0; j<M; j++){
//                    cout << " " << ck[i][j];
//                }
//                cout << endl;
//            }
//            cout << endl;
        }
        return;
    }
    if(tmp_no == 2){
        for(int i=0; i<2; i++){
            paint(tmp_y,tmp_x,i,0);
            paint(tmp_y,tmp_x,i+2,0);
            dfs(tmp_no,idx+1,cnt+1);
            paint(tmp_y,tmp_x,i,1);
            paint(tmp_y,tmp_x,i+2,1);
        }
        return;
    }
    if(tmp_no == 3){
        for(int i=0; i<4; i++){
            paint(tmp_y,tmp_x,i,0);
            paint(tmp_y,tmp_x,(i+1)%4,0);
            dfs(tmp_no,idx+1,cnt+1);
            paint(tmp_y,tmp_x,i,1);
            paint(tmp_y,tmp_x,(i+1)%4,1);
        }
        return;
    }
    if(tmp_no == 4){
        for(int i=0; i<4; i++){
            paint(tmp_y,tmp_x,i,0);
            paint(tmp_y,tmp_x,(i+1)%4,0);
            paint(tmp_y,tmp_x,(i+2)%4,0);
            dfs(tmp_no,idx+1,cnt+1);
            paint(tmp_y,tmp_x,i,1);
            paint(tmp_y,tmp_x,(i+1)%4,1);
            paint(tmp_y,tmp_x,(i+2)%4,1);
        }
        return;
    }
    if(tmp_no == 5){
        paint(tmp_y,tmp_x,0,0);
        paint(tmp_y,tmp_x,1,0);
        paint(tmp_y,tmp_x,2,0);
        paint(tmp_y,tmp_x,3,0);
        dfs(tmp_no,idx+1,cnt+1);
        return;
    }
    
    
    return;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> mp[i][j];
            if(mp[i][j] != 0 && mp[i][j] != 6){
                node n1;
                n1.y = i; n1.x = j; n1.dis = mp[i][j];
                que.push_back(n1);
            }
        }
    }
    dfs(0,0,0);
    cout << ans;
}

