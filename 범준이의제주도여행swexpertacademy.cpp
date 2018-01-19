#include <iostream>
#include <vector>
#define airPort 0;
#define hoTel 1;
#define plAce 2;
enum {
    air,
    hot,
    pot
};

using namespace std;

int T,N,M,air_idx,arrP;
char spot;
int map[36][36];
bool visited[36];
int maxV = -1;
int dis[36],sat[36],kind[36];
vector <int> path,ansP;

void dfs(int idx,int days,int times,int satis,int cnt){
    path[cnt] = idx + 1;
    
    if(days > M)
        return;
    
    if(days == M && kind[idx] == 0){
        if(maxV < satis){
            maxV = satis;
            arrP = cnt;
            for(int i=0; i<=cnt; i++){
                ansP[i] = path[i];
            }
        }
        return;
    }
    
    if(kind[idx] == 0) return;
    
    for(int i=0; i<N; i++){
        if(visited[i] == 1) continue;
        
        if(kind[i] == 1){
            if(kind[idx] == 1)
                continue;
            if(days == M) continue;
            if(map[idx][i] + times <= 540){
                dfs(i,days+1,0,satis,cnt+1);
            }
        }else{
            if(map[idx][i] + times + dis[i] >= 540) continue;
            visited[i] = 1;
            dfs(i,days,times+map[idx][i]+dis[i],satis+sat[i],cnt+1);
            visited[i] = 0;
        }
    }
    return;
}

int main(){
    cin >> T;
    for(int tc=1; tc<=T; tc++){
        cin >> N >> M;
        path.resize(N+1);
        ansP.resize(N+1);
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                cin >> map[i][j];
                map[j][i] = map[i][j];
            }
        }
        
        for(int i=0; i<N; i++){
            cin >> spot;
            if(spot == 'A'){
                kind[i] = airPort;
                air_idx = i;
            }
            if(spot == 'H'){
                kind[i] = hoTel;
            }
            if(spot == 'P'){
                kind[i] = plAce;
                cin >> dis[i] >> sat[i];
            }
        }
        
        for(int i=0; i<N; i++){
            if(kind[i] == 2){
                visited[i] = 1;
                dfs(i,1,map[air_idx][i] + dis[i], sat[i], 0);
                visited[i] = 0;
            }
        }
        cout << "#" << tc << " " << maxV << " ";
        if(maxV != 0){
            for(int i=0; i<=arrP; i++)
                cout << ansP[i] << " ";
        }
        cout << endl;
        maxV = 0;
    }
}

