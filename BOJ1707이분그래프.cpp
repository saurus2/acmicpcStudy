#include <iostream>
#include <vector>
#include <memory.h>
#define MAXV 20001
using namespace std;
vector<int> G[MAXV];
int C[MAXV];
bool dfs(int v, int c){
    C[v] = c;//색칠하기
    for(int i=0; i<G[v].size(); i++){
        if(C[G[v][i]] == c){
            return false;
        }
        if(C[G[v][i]] == 0 && !dfs(G[v][i],-c)){
            //다른색으로 칠하러 들어갔을때 인접한 노드가 색이 같으면 실패
            return false;
        }
    }
    return true;
}
int main(){
    int t,v,e;
    cin >> t;
    while(t--){
        bool is = true;
        memset(C, 0, sizeof(C));
        memset(G, 0, sizeof(G));
        cin >> v >> e;
        for(int i=0; i<e; i++){
            int be,en;
            cin >> be >> en;
            G[be].push_back(en);
            G[en].push_back(be);
            //무방향성 그래프
            if(be == en){
                is = false;
                break;
            }
        }
        for(int i=0; i<v; i++){
            if(C[i] == 0){
                if(!dfs(i,1)){
                    //모든 노드에 대해서 검색
                    is=false;
                    break;
                }
            }
        }
        if(is == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
