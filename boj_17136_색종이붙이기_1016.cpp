#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair <int,int> pii;
vector <pii> vc;
int mp[11][11],visited[11][11],boxCnt[6],answer;
void input(){
    answer=1000000000;
    for(int i=1; i<=5; i++)
        boxCnt[i]=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> mp[i][j];
            if(mp[i][j]==1){
                vc.push_back({i,j});
            }
            visited[i][j]=0;
        }
    }
}
void dfs(int idx,int vcS){
    if(idx>vcS) return;
    int endf=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(mp[i][j]==1 && visited[i][j]==0)
                endf=1;
        }
    }
    if(endf==0){
        int tmp=0;
        for(int i=1; i<=5; i++){
            tmp+=boxCnt[i];
        }
        answer=min(answer,tmp);
        return;
    }
    int cy=vc[idx].first;
    int cx=vc[idx].second;
    if(visited[cy][cx]==1){
        dfs(idx+1,vcS);
    }
    for(int i=5; i>=1; i--){
        int f=0;
        for(int j=0; j<i; j++){
            for(int k=0; k<i; k++){
                int ny=cy+j;
                int nx=cx+k;
                if(mp[ny][nx]==0 || visited[ny][nx]==1 || ny<0||nx<0||ny>=10||nx>=10){
                    f=1;
                    break;
                }
            }
            if(f==1) break;
        }
        if(f==1) continue;
        
        if(boxCnt[i]+1>5){
            f=1;
            continue;
        }
        for(int j=0; j<i; j++){
            for(int k=0; k<i; k++){
                visited[cy+j][cx+k]=1;
            }
        }
        boxCnt[i]++;
        dfs(idx+1,vcS);
        boxCnt[i]--;
        for(int j=0; j<i; j++){
            for(int k=0; k<i; k++){
                visited[cy+j][cx+k]=0;
            }
        }
    }
    
}
int main(){
    input();
    int vcSize=vc.size();
    dfs(0,vcSize);
    if(answer == 1000000000)
        cout << "-1" << endl;
    else
        cout << answer << endl;
}

