#include <iostream>
#include <utility>
#include <memory.h>
#include <algorithm>
using namespace std;

int mp[1001][1001];
int dist[1001];
int visit[1001];
int N,M;
int st,des;

int main(){
    scanf("%d", &N);
    scanf("%d", &M);
    for(int i=1; i<=N; i++){
        dist[i] = 1000000000;
        visit[i] = 0;
        for(int j=1; j<=N; j++){
            if(i!=j)
                mp[i][j] = 1000000000;
        }
    }
    for(int i=0; i<M; i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        if(mp[a][b] > c)
            mp[a][b] = c;
    }
    scanf("%d %d", &st, &des);
    
    dist[st] = 0;
    int v = st;

    for(int i=1; i<=N; i++){
        int minV = 1000000000;
        for(int j=1; j<=N; j++){
            if(visit[j] == 0 && minV > dist[j]){
                minV = dist[j];
                v = j;
            }
        }
        visit[v] = 1;
        
        for(int j=1; j<=N; j++){
            if(dist[j] > dist[v] + mp[v][j])
                dist[j] = dist[v] + mp[v][j];
        }
    }
    printf("%d", dist[des]);
}

