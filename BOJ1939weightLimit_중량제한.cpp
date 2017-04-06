#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int n,m;
int start, dest;
vector<pair<int,int>> graph[100001];
int visit[100001];
queue<int> que;

int bfs(int limit){
    memset(visit,0,sizeof(visit));
    while(!que.empty()) que.pop();
    //방문 체크배열과 큐 모두 초기화
    que.push(start);
    //시작 점부터 큐에 넣고 bfs 시작
    visit[start]=1;
    
    while(!que.empty()){
        int current = que.front();
        que.pop();
        
        if(current==dest) return 1;
        //현재의 좌표가 도착지면 리턴
        
        for(int i=0; i<graph[current].size(); i++){
            int next = graph[current][i].first;
            int w = graph[current][i].second;
            
            if(visit[next] == 0 && limit <= w){
                //bfs로 처음 정한 최대 가중치 보다 클때만 길을 찾아나선다
                //작으면 가중치가 짐을 내려야하기 때문에 정답을 찾는데 필요하지 않은 방법.
                visit[next] = 1;
                que.push(next);
            }
        }
    }
    return 0;
}

int solve(int e){
    int s = 0, middle;
    //가장 큰 가중치부터 값을 찾는다
    while(s<=e){
        middle = (s + e)/2;
        if(bfs(middle)) //이중 탐색으로 가장큰 가중치부터 검색해나간다
            s=middle+1;
        else
            e=middle-1;
        
    }
    return e;
}

int main(){
    int one, two, weight;
    int mx = 0;
    memset(visit,0,sizeof(visit));
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        cin >> one >> two >> weight;
        graph[one].push_back(make_pair(two,weight));
        graph[two].push_back(make_pair(one,weight));
        
        if(weight > mx) mx = weight;
        //가장 큰 가중치를 찾는다.
    }
    
    cin >> start >> dest;
    cout << solve(mx) << endl;
    
    return 0;
}
