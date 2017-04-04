#include <iostream>
#include <queue>
using namespace std;
#define INF 100000001
#define mp make_pair
int bus[1001][1001]={0};
int dist[1001]={0};
priority_queue <pair <int,int>> que;
int main(){
    int n,m,a,b,v;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            bus[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++)
    {
        cin >> a >> b >> v;
        bus[a][b] = bus[a][b] > v ? v : bus[a][b];
    }
    cin >> a >> b;
    for(int i=1; i<=n; i++){
        dist[i] = INF;
    }
    que.push(mp(a,0));
    dist[a] = 0;
    while(!que.empty()){
        int current = que.top().first;
        int currentcost = que.top().second;
        que.pop();
        if(currentcost <= dist[current]){
            for(int i=1; i<=n; i++){
                if(bus[current][i] < INF){
                    if(currentcost + bus[current][i] < dist[i]){
                        dist[i] = currentcost + bus[current][i];
                        que.push(mp(i,dist[i]));
                    }
                }
            }
        }
    }
    cout << dist[b];
    return 0;
}
