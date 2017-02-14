#include <stdio.h>
int main(){
    int i,t,res;
    for(scanf("%d",&t);t--;){
        int dp[12]={0,};
        dp[0]=1;
        scanf("%d",&res);
        for(i=1;i<=res;i++){
            if((i-1)>=0) dp[i] += dp[i-1];
            if((i-2)>=0) dp[i] += dp[i-2];
            if((i-3)>=0) dp[i] += dp[i-3];
        }
        printf("%d\n",dp[res]);
    }
    return 0;
}
