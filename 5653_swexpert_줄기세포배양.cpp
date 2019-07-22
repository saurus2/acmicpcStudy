#include <iostream>
#include <queue>
using namespace std;
#define maxv 150
typedef pair < int,int >  pii;
int N,M,K,T,val,answer;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
struct node{
    int status=0;
    int activeTime=0;
    int unActiveTime=0;
    int life=0;
};
node mp[352][352];
queue < pii > que;
void input(){
    answer=0;
    cin >> N >> M >> K;
    for(int i=0; i<352; i++){
        for(int j=0; j<352; j++){
            mp[i][j].status=0;
            mp[i][j].activeTime=0;
            mp[i][j].unActiveTime=0;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> val;
            if(val>0){
                mp[i+maxv][j+maxv].life=val;
                mp[i+maxv][j+maxv].activeTime=val;
                mp[i+maxv][j+maxv].unActiveTime=val;
                mp[i+maxv][j+maxv].status=1;
            }
        }
    }
}

//status :: 0 empty :: 1 equp :: 2 active :: 3 dead
void checkFunc(){
    for(int i=0; i<352; i++){
        for(int j=0; j<352; j++){
            if(mp[i][j].status==1){
                if(mp[i][j].unActiveTime>0){
                    mp[i][j].unActiveTime--;
                }
                if(mp[i][j].unActiveTime==0){
                    mp[i][j].status=2;
                }
            }else if(mp[i][j].status==2){
                if(mp[i][j].activeTime>0){
                    que.push({i,j});
                    mp[i][j].activeTime--;
                }
                if(mp[i][j].activeTime==0){
                    mp[i][j].status=3;
                }
            }
        }
    }
    while(!que.empty()){
        int curI=que.front().first;
        int curJ=que.front().second;
        int curLife=mp[curI][curJ].life;
        que.pop();
        for(int i=0; i<4; i++){
            int nextI = curI+dy[i];
            int nextJ = curJ+dx[i];
            if(mp[nextI][nextJ].status==0){
                mp[nextI][nextJ].status=1;
                mp[nextI][nextJ].activeTime=curLife;
                mp[nextI][nextJ].unActiveTime=curLife;
                mp[nextI][nextJ].life=curLife;
            }else if(mp[nextI][nextJ].status==1){
                if(mp[nextI][nextJ].unActiveTime==mp[nextI][nextJ].life){
                    if(mp[nextI][nextJ].life<curLife){
                        mp[nextI][nextJ].activeTime=curLife;
                        mp[nextI][nextJ].unActiveTime=curLife;
                        mp[nextI][nextJ].life=curLife;
                    }
                }
            }
        }
    }
}

void pf(){
    for(int i=maxv-10; i<maxv+10; i++){
        for(int j=maxv-10; j<maxv+10; j++){
            cout << mp[i][j].status << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void func(){
    for(int i=1; i<=K; i++){
        //cout << i-1 << ":: time" << endl;
        //pf();
        checkFunc();
    }
}

int main(){
    cin >> T;
    for(int tc=1; tc<=T; tc++){
        input();
        func();
        for(int i=0; i<352; i++){
            for(int j=0; j<352; j++){
                if(mp[i][j].status==1 || mp[i][j].status==2){
                    answer++;
                }
            }
        }
        cout << "#" << tc << " " << answer << endl;
    }
}

