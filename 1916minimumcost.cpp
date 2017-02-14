#include <stdio.h>
#define min(a,b) (a < b ? a : b)
//I need to use priority Queue. 
int main(){
    int n,m,src,des,cost,i,j;
    scanf("%1d",&n);
    scanf("%1d",&m);
    int map[1001][1001] = {0,};
    int Q[1002],dist[1002],Q_size;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i==j)
                map[i][j] = 0;
            else
                map[i][j] = 999;
        }
    }
    for(i=1; i<=m; i++){
        scanf("%d %d %d",&src,&des,&cost);
        if(map[src][des] > cost)
            map[src][des]=cost;
    }
    scanf("%d %d",&src,&des);
    
    Q_size=n;
    for(int v=1; v<=n;v++){
        dist[v] = 999;
        Q[v] = 0;
    }
    dist[src] = 0;
    
    while(Q_size != 0){
        int min_dst = 999, u = 0;
        for(int v = 1; v<=n; v++){
            if(Q[v] == 0 && dist[v] < min_dst)
            {
                min_dst = dist[v];
                u = v;
            }
        }
        Q[u] = 1;
        Q_size--;
        for(int v =1; v <=n; v++){
            if(map[u][v] == 999)continue;
            if(dist[u]+map[u][v] < dist[v])
                dist[v] = dist[u]+map[u][v];
        }
    }
    
    printf("%d\n",dist[des]);
    
    return 0;
}
