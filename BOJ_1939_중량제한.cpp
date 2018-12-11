#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
#include <cstdio>
using namespace std;
int N,M,a,b,c,maxVal=-1,start,des,answer = -1;
int visited[10001];
typedef pair < int, int > pi;
vector < pi > vc[10001];



int bfs(int weight){
    queue < pi > que; // que 새로 생성 
    que.push({weight,start});// weight 빼기.
    visited[start] = 1;
    while(!que.empty()){
        int val = que.front().first;
        int cur = que.front().second;
        que.pop();
        
        for(int i=0; i<vc[cur].size(); i++){
            int nVal = vc[cur].at(i).first;
            int next = vc[cur].at(i).second;
            if(val > nVal) continue;
            if(visited[next] == 1) continue;
            visited[next] = 1;
            que.push({val, next});
            if(next == des){
                return val;
            }
        }
    }
    return -1;
}

void bs(){
    int mid, begin, last, tmp; // begin -> first
    begin = 0;
    last = maxVal;
    while(begin<=last){
        mid = (begin + last) / 2;
        memset(visited, 0, sizeof(visited));
        tmp = bfs(mid);
        if(tmp == -1){
            last = mid-1;
        }else{
            if(tmp > answer)
                answer = tmp;
            begin = mid+1;
        }
    }
    return;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c);
        vc[a].push_back({c,b});
        vc[b].push_back({c,a});
        if(c>maxVal)
            maxVal = c;
    }
    scanf("%d %d", &start, &des);
    bs();
    printf("%d\n" , answer);
    return 0;
}

