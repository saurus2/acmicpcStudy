#include <iostream>
using namespace std;
int main(){
    int n,dp[16]={0},ar[16][2]={0};
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ar[i][0] >> ar[i][1];
    }
    
    for(int i=0; i<=n; i++){
        dp[ar[i][0]+i] = max(dp[ar[i][0]+i], dp[i] + ar[i][1]);
        dp[i+1] = max(dp[i+1],dp[i]);
        for(int j=0; j<=n; j++){
            cout << " " << dp[j];
        }
        cout << endl;
    }
    cout << dp[n];
    return 0;
}
