#include <iostream>
using namespace std;
int main(){
    int n,dp[301][2]={0},s[301]={0};
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> s[i];
    }
    
    dp[1][0] = dp[1][1] = s[1];
    
    for(int i=2; i<=n; i++){
        dp[i][0] = dp[i-1][1] + s[i];
        dp[i][1] = max(dp[i-2][0],dp[i-2][1]) + s[i];
    }
    
    cout << max(dp[n][0],dp[n][1]);
    
    return 0;
}
