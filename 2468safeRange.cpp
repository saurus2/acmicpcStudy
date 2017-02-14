#include <stdio.h>
int xd[]={0,0,1,-1},yd[]={1,-1,0,0},ar[101][101]={0,},no=0,maxn =0,cnt=0,visited[101][101]={0,},maxCnt=-1;
void dfs(int x,int y,int hight){
    if(x>=no||y>=no||x<0||y<0||ar[x][y]<=hight||visited[x][y]) return;
    visited[x][y]=1;
    for(int i=0; i<4; i++)dfs(x+xd[i],y+yd[i],hight);
}

int main(){
    scanf("%d",&no);
    for(int i = 0; i < no; i++) {
        for(int j = 0; j < no; j++) {
            scanf("%d",&ar[i][j]);
        }
    }
    for(int i = 0; i<=100; i++){
        for(int j = 0; j < no; j++){
            for(int k = 0; k < no; k++){
                if(!visited[j][k]&&ar[j][k]>i){
                    dfs(j,k,i); maxn++;
                }
            }
        }
        if(maxn>maxCnt)
            maxCnt = maxn;
        maxn=0;
        for(int i = 0; i < no; i++) for(int j = 0; j < no; j++) visited[i][j] = 0;
    }
    printf("%d",maxCnt);
    return 0;
}
