#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 87654321
#define MAX_V 20001

typedef pair<int, int> adjpoint;
typedef pair<int, int> point;
vector <adjpoint> adj[MAX_V];

int main(){
    int V, E;
    cin >> V >> E;
    int K;
    cin >> K;
    for(int i=0; i<E; ++i){
        int s,e,w;
        cin >> s >> e >> w;
        adj[s].push_back(adjpoint(e,w));
        //        인접 리스트에 출발점 끝점 가중치력입력
    }
    vector<int> dist(V+1, INF);
    //INF로 V+1개만큼 백터 생성
    dist[K] = 0;
    
    priority_queue<point> pq;
    pq.push(point(0,K));
    //    출발점 0 가중치를 큐에삽입
    while(!pq.empty()){
        int cost = -pq.top().first;
        //        정렬을 위해 -를 붙여서 삽입
        int here = pq.top().second;
        pq.pop();
        
        if(cost > dist[here]) continue;
        //        큐에 들어간 가중치가 지금 현재 위치보다 클경우 검사 안함
        for(int i=0; i<adj[here].size(); ++i){
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(nextDist < dist[there]){
                dist[there] = nextDist;
                pq.push(point(-nextDist, there));
                //정렬을 위해 -를 곱해서 넣음
            }
        }
    }
    for(int i=1; i<=V; ++i){
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}
