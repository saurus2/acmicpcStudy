#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair < int , pair < int, int > > piii;
typedef pair < pair < pair < int, int > , pair < int, int > > , int > piiiii;
vector <piii> mp[101][101];
vector <piii> mpcp[101][101];
vector <piiiii> vc;
int answer,R,C,M,r,c,s,d,z,fIdx,bp=0;
int dy[5]={0,-1,1,0,0};
int dx[5]={0,0,0,1,-1};
void input(){
    fIdx=0;
    bp=0;
    answer=0;
    cin >> R >> C >> M;
    for(int i=0; i<M; i++){
        cin >> r >> c >> s >> d >> z;
        mp[r][c].push_back({z,{s,d}});
    }
}
void fishing(){
    fIdx++;
    for(int i=1; i<=R; i++){
        if(mp[i][fIdx].size()!=0){
            answer+=mp[i][fIdx].front().first;
            mp[i][fIdx].clear();
            break;
        }
    }
}
int overCk(int r,int c){
    if(r<1 || c<1 || r>R || c>C) return 1;
    return 0;
}
void moving(int r,int c,int z,int s,int d){
    int nr=r;
    int nc=c;
    int tmpr=0;
    int tmpc=0;
    for(int i=0; i<s; i++){
        tmpr=nr+dy[d];
        tmpc=nc+dx[d];
        if(overCk(tmpr,tmpc)==1){
            if(d==1)
                d=2;
            else if(d==2)
                d=1;
            else if(d==3)
                d=4;
            else if(d==4)
                d=3;
            nr+=dy[d];
            nc+=dx[d];
        }else{
            nr+=dy[d];
            nc+=dx[d];
        }
    }
    mp[nr][nc].push_back({z,{s,d}});
}
void shark(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(mp[i][j].size()!=0){
                vc.push_back({{{i,j},{mp[i][j].front().first,mp[i][j].front().second.first}},mp[i][j].front().second.second});
                mp[i][j].clear();
            }
        }
    }
    int vcSize=(int)vc.size();
    if(vcSize==0){
        bp=1;
        vc.clear();
        return;
    }
        
    for(int i=0; i<vcSize; i++){
        int r=vc[i].first.first.first;
        int c=vc[i].first.first.second;
        int z=vc[i].first.second.first;
        int s=vc[i].first.second.second;
        int d=vc[i].second;
        moving(r, c, z, s, d);
    }
    vc.clear();
}
void arrange(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(mp[i][j].size()>1){
                sort(mp[i][j].begin(),mp[i][j].end());
                int tmpZ=mp[i][j][mp[i][j].size()-1].first;
                int tmpS=mp[i][j][mp[i][j].size()-1].second.first;
                int tmpD=mp[i][j][mp[i][j].size()-1].second.second;
                mp[i][j].clear();
                mp[i][j].push_back({tmpZ,{tmpS,tmpD}});
            }
        }
    }
}
int main(){
    input();
    for(int i=0; i<C; i++){
        if(bp==1)
            break;
        fishing();
        shark();
        arrange();
    }
    cout << answer;
}


