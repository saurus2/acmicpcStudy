#include <iostream>
#include <queue>
#define MAX 101
#define INF 99999999
using namespace std;
int n,m;
vector<pair<int,int>> adj[MAX];

void InData(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int src,dst;
        cin>>src>>dst;
        adj[src].push_back(make_pair(dst,1));
        adj[dst].push_back(make_pair(src,1));
    }
}

int Dikstra(int node){
    priority_queue<pair<int,int>> pq;
    vector<int> dist(MAX,INF);
    dist[node] = 0;
    pq.push(make_pair(0,node));
    
    while(!pq.empty()){
        int min_dist = -pq.top().first;
        int min_node = pq.top().second;
        pq.pop();
        for(int v = 0; v < adj[min_node].size();v++){
            int next_node = adj[min_node][v].first;
            int next_dist = min_dist + adj[min_node][v].second;
            if(next_dist < dist[next_node]){
                dist[next_node] = next_dist;
                pq.push(make_pair(-next_dist,next_node));
            }
        }
    }
    int ret = 0;
    for(int i=1; i<=n; i++)
        ret+=dist[i];
    return ret;
}

int main(){
    int kevin;
    int min_kevin = INF, min_node;
    
    InData();
    
    for(int v = 1; v<=n; v++)
    {
        kevin = Dikstra(v);
        if(kevin < min_kevin){
            min_kevin = kevin;
            min_node = v;
        }
    }
    cout << min_node << endl;
    return 0;
}
