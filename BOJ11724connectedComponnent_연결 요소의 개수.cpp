#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> g[7];
int check[7]={0};
int cnt = 0;
queue <int> que;
void bfs(int x){
    check[x] = 1;
    que.push(x);
    while(!que.empty()){
        int np = que.front();
        que.pop();
        for(int i=0; i<g[np].size(); i++){
            int next = g[np][i];
            if(check[next] == 0){
                check[next]=1;
                que.push(next);
            }
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int v,e;
        cin >> v >> e;
        g[v].push_back(e);
        //연결요소 - 두점이 방향에 상관없이 연결된 것
        g[e].push_back(v);
    }
    for(int i=1; i<=n; i++){
        if(check[i]==0){
            //정점이 1개만 있더라도 연결요소 1개로 봐야함
            bfs(i);
            cnt++;
        }
    }
    cout << cnt;
}
