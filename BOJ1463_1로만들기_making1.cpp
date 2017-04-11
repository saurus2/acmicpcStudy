#include <iostream>
#define INF 87654321
using namespace std;
int dp[1000001], n;
int main(){
    cin >> n;
    for(int i=0; i<=n; i++) dp[i] = INF;
    //최대값으로 초기화
    dp[n] = 0;
    //현재 값은 0
    for(int i=n; i>=1; i--){
        if(dp[i] == INF) continue;//연산 후 영향 끼치지 않는 숫자는 통과
        if(i-1>=1)dp[i-1] = min(dp[i-1],dp[i]+1);
        if((i%2)==0) dp[i/2] = min(dp[i/2],dp[i]+1);
        if((i%3)==0) dp[i/3] = min(dp[i/3],dp[i]+1);
        //+1,/2,/3외 될때만 확인하여 저장해나감
    }
    cout << dp[1];
    return 0;
}
