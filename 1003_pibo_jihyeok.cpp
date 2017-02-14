#include <stdio.h>
int main(){
    int dp[41][2]={0};
    int n=0,t=0;
    scanf("%d",&n);
    dp[0][0]=1; dp[0][1]=0;
    //0이 출력하는 0의 갯수 1, 1의 갯수 0
    dp[1][0]=0; dp[1][1]=1;
    //1이 출력하는 0의 갯수 0, 1의 갯수 1
    for(int i=2; i<41; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
        //2를 호출했을때 0과 1에서 나온 값을 더해서 저장
        //계산된 값을 중첩하여 더해 나감
    }
    for(int i=0; i<n; i++) {
        scanf("%d",&t);
        printf("%d %d\n",dp[t][0],dp[t][1]);
    }
    return 0;
}
