#include <stdio.h>
int n,i,j,a,b,no,cnt;
int ar[30][30];
int ans[1000]={0,};

void dfs(int x,int y){
    ar[x][y] = no;
    if(ar[x][y+1]==1){cnt++;dfs(x,y+1);}
    if(ar[x][y-1]==1){cnt++;dfs(x,y-1);}
    if(ar[x+1][y]==1){cnt++;dfs(x+1,y);}
    if(ar[x-1][y]==1){cnt++;dfs(x-1,y);}
}

int main(){
    no=2;
    cnt=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%1d",&ar[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(ar[i][j]==1){
                dfs(i,j);
                ans[no]=cnt;
                no++;
                cnt=1;
            }
        }
    }
    int tmp =0;
    for(i=0;i<no;i++){
        for(j=0;j<no-1-i;j++){
            if(ans[j]>ans[j+1])
            {
                tmp=ans[j];
                ans[j]=ans[j+1];
                ans[j+1]=tmp;
            }
        }
    }
    printf("%d\n",no-2);
    for(i=2;i<no;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
