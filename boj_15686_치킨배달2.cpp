#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <int, int> pii;
int n,m,ans,mp[51][51],hsCnt,ckCnt;
vector <pii> house;
vector <pii> chicken;
int ck[14];
void input(){
    cin >> n >> m;
    house.clear();
    chicken.clear();
    ckCnt=0;
    ans=1000000000;
    for(int i=0; i<14; i++)
        ck[i]=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mp[i][j];
            if(mp[i][j]==1){
                house.push_back({i,j});
            }
            if(mp[i][j]==2){
                chicken.push_back({i,j});
            }
        }
    }
}
int cal(){
    int sum=0;
    for(int i=0; i<hsCnt; i++){
        int mv=100000000;
        for(int j=0; j<ckCnt; j++){
            if(ck[j]==1){
                int tmp=abs(chicken[j].first-house[i].first) + abs(chicken[j].second - house[i].second);
                mv=min(tmp,mv);
            }
        }
        sum+=mv;
    }
    return sum;
}
void dfs(int idx,int cnt){
    if(idx>ckCnt) return;
    if(cnt==m){
        ans=min(ans,cal());
        return;
    }
    
    ck[idx]=1;
    dfs(idx+1,cnt+1);
    ck[idx]=0;
    dfs(idx+1,cnt);
}
int main(){
    input();
    hsCnt=house.size();
    ckCnt=chicken.size();
    dfs(0,0);
    cout << ans << endl;
}

