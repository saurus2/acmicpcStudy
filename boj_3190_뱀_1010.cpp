#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef pair < int, int > pii;
vector <pii> vc;
deque <pii> sn;
int n,k,l,mp[101][101],sy,sx,sDis,answer;
int dixy[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
void input(){
    answer=0;
    cin >> n;
    cin >> k;
    for(int i=0; i<k; i++){
        int y,x;
        cin >> y >> x;
        mp[y-1][x-1]=1;
    }
    cin >> l;
    for(int i=0; i<l; i++){
        int cnt;
        char dis;
        cin >> cnt >> dis;
        if(dis=='D'){
            vc.push_back({cnt,0});
        }else if(dis=='L'){
            vc.push_back({cnt,1});
        }
    }
}
void mSnack(){
    sy=0,sx=0,sDis=0;
    sn.push_back({sy,sx});
    int vcSize=(int)vc.size();
    int vcI=0;
    int mCnt=vc[vcI].first;
    int mDis=vc[vcI].second;
    while(1){
        answer++;
        if(answer > mCnt && vcI < vcSize){
            vcI++;
            mCnt=vc[vcI].first;
            mDis=vc[vcI-1].second;
            if(mDis==0){
                sDis=(sDis+1)%4;
            }else if(mDis==1){
                sDis=(sDis+3)%4;
            }
        }
        int ny=sn.front().first+dixy[sDis][0];
        int nx=sn.front().second+dixy[sDis][1];
        if(ny<0||nx<0||ny>=n||nx>=n){
            cout << answer << endl;
            return;
        }
        int snSize=(int)sn.size();
        for(int si=1; si<snSize; si++){
            if(ny==sn.at(si).first&&nx==sn.at(si).second){
                cout << answer << endl;
                return;
            }
        }
        
        if(mp[ny][nx]==0){
            sn.pop_back();
            sn.push_front({ny,nx});
        }else if(mp[ny][nx]==1){
            sn.push_front({ny,nx});
            mp[ny][nx]=0;
        }
    }
    return;
}
int main(){
    input();
    mSnack();
}

