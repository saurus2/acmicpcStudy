#include <iostream>
#include <vector>
using namespace std;
typedef pair < int, int > pii;
struct node{
    int y,x,d,e;
};
vector <node> que;
int ck[4001][4001];
int T,N,tmpD,tmpE,ansSum,tmpY,tmpX;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmpX >> tmpY >> tmpD >> tmpE;
        node curNode;
        curNode.x=(tmpX+1000)*2;
        curNode.y=(tmpY+1000)*2;
        curNode.d=tmpD;
        curNode.e=tmpE;
        que.push_back(curNode);
    }
    for(int i=0; i<=4000; i++){
        for(int j=0; j<=4000; j++){
            ck[i][j]=0;
        }
    }
    ansSum=0;
}
int overCk(int y,int x){
    if(y>4000 || x>4000 || y<0 || x<0) return 1;
    return 0;
}
void move(){
    while(!que.empty()){
        int queSize = (int)que.size();
//        if(queSize==1) return;
        for(int i=0; i<queSize; i++){
            int ny = que[i].y + dy[que[i].d];
            int nx = que[i].x + dx[que[i].d];
            if(overCk(ny,nx)==1){
                que[i].e=0;
                continue;
            }
            que[i].y=ny;
            que[i].x=nx;
            ck[ny][nx]+=que[i].e;
        }
        for(int i=0; i<queSize; i++){
            if(que[i].e==0) continue;
            if(ck[que[i].y][que[i].x]!=que[i].e){
                ansSum += ck[que[i].y][que[i].x];
                ck[que[i].y][que[i].x]=0;
                que[i].e=0;
            }
        }
        vector <node> tmp;
        tmp.assign(que.begin(),que.end());
        que.clear();
        for(int i=0; i<(int)tmp.size(); i++){
            if(tmp[i].e!=0){
                que.push_back(tmp[i]);
            }
        }
        for(int i=0; i<=4000; i++){
            for(int j=0; j<=4000; j++){
                ck[i][j]=0;
            }
        }
    }
}
int main(){

    cin >> T;
    for(int tc=1; tc<=T; tc++){
        input();
        move();
        cout << "#" << tc << " " << ansSum << endl;
    }
}

