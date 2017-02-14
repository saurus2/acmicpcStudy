#include <stdio.h>
#include <algorithm>
int m,n,k,x,y,x2,y2,a,b,arcnt = 0;
int table[101][101] = {0,};
int size[1000001] = {0,};
int xd[4] = {0,0,1,-1};
int yd[4] = {1,-1,0,0};

void dfs(int x,int y){
    if(x>=m || y>=n || table[x][y] == 1 || x<0 || y<0)
        return;
    table[x][y] = 1;
    size[arcnt]++;
    for(int i=0; i<4; i++) dfs(x+xd[i],y+yd[i]);
}

int main(){
    scanf("%d %d %d",&m,&n,&k);
    for(int i=0; i<k; i++){
        scanf("%d %d %d %d",&x,&y,&x2,&y2);
        for(a=x; a<x2; a++) for(b=y; b<y2; b++) table[b][a] = 1;
    }
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) if(!table[i][j]) dfs(i,j), arcnt++;
    std::sort(size,size+arcnt);
    printf("%d\n",arcnt);
    for(int i = 0; i < arcnt; i++) printf("%d ",size[i]);
    return 0;
}
