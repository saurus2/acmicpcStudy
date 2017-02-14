#include <stdio.h>
int main(){
    int n=0,m=0,i=0,j=0,x=0,y=0,k=0,ar[301][301]={0};
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d",&ar[i][j]);
            ar[i][j] += ar[i][j-1] + ar[i-1][j] - ar[i-1][j-1];
            //dp로 합을 저장할 2차원 배열을 생성한다.
            //그림으로 그려보면 이해하기 쉬움.
        }
    }
    scanf("%d",&k);
    for(int p=0; p<k; p++){
        scanf("%d %d %d %d",&i,&j,&x,&y);
        printf("%d\n", ar[x][y] - ar[i-1][y] - ar[x][j-1] + ar[i-1][j-1]);
        //원하는 범위의 합을 구하는 식.
        //그림으로 그려서 확인하면 이해가 쉬움.
    }
    return 0;
}
