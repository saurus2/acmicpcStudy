#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int T,N,W,H,mp[20][20],cpMp[20][20],ckmp[20][20],ptck[20],answer=10000000;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
deque <int> deq;
void pf(){
    cout << endl;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << mp[i][j] << " ";
            ckmp[i][j]=0;
        }
        cout << endl;
    }
}
void input(){
    cin >> N >> W >> H;
    for(int i=0; i<H; i++){
        ptck[i]=0;
        for(int j=0; j<W; j++){
            cin >> mp[i][j];
        }
    }
}
void deqPf(){
    int deqSize=(int)deq.size();
    cout << endl << "::dequ " ;
    for(int i=0; i<deqSize; i++){
        cout << deq.at(i) << " ";
    }
}
void arrange(){
    for(int i=0; i<W; i++){
        for(int j=0; j<H; j++){
            for(int k=H-1; k>j; k--){
                if(mp[k][i]==0){
                    int tmp=mp[k-1][i];
                    mp[k-1][i]=mp[k][i];
                    mp[k][i]=tmp;
                }
            }
        }
    }
}
void bomb(int y,int x){
    if(mp[y][x]==0)
        return;
    int mpVal=mp[y][x];
    ckmp[y][x]=1;
    if(mpVal==1){
        mp[y][x]=0;
        return;
    }else{
        for(int i=0; i<4; i++){
            int nextY=y;
            int nextX=x;
            for(int j=0; j<mpVal-1; j++){
                nextY+=dy[i];
                nextX+=dx[i];
                if(ckmp[nextY][nextX]==1)
                    continue;
                if(nextY<0||nextX<0||nextY>=H||nextX>=W) break;
                if(mp[nextY][nextX]!=0){
                    bomb(nextY,nextX);
                }
            }
        }
        mp[y][x]=0;
    }
}
void down(int y, int x){
    int tmpy=0;
    while(1){
        if(mp[tmpy][x]!=0)
            break;
        tmpy++;
        if(tmpy>=H)
            return;
    }
    bomb(tmpy,x);
}
int cntMp(){
    int tmpCnt=0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(mp[i][j]>0)
                tmpCnt++;
        }
    }
    return tmpCnt;
}
void cpm(int n){
    if(n==0){
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cpMp[i][j]=mp[i][j];
            }
        }
    }else if(n==1){
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                mp[i][j]=cpMp[i][j];
            }
        }
    }
}
void ckmpClean(){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            ckmp[i][j]=0;
        }
    }
}
void dfs(int idx, int cnt){
    if(cnt>=N){
        cpm(1);
        int deqSize=(int)deq.size();
        for(int i=0; i<deqSize; i++){
            int tmp=deq.at(i);
            ckmpClean();
            down(0,tmp);
            arrange();
        }
        answer=min(answer,cntMp());
        return;
    }
    
    for(int i=0; i<W; i++){
        deq.push_back(i);
        dfs(i,cnt+1);
        deq.pop_back();
    }
}
int main(){
    cin >> T;
    for(int tc=1; tc<=T; tc++){
        input();
        cpm(0);
        ckmpClean();
        answer=10000000;
        deq.clear();
        dfs(0,0);
        cout << answer << endl;
    }
//    arrange();
//    pf();
}


