#include <iostream>
using namespace std;
long long dp[91]={0};
int main(){
    int n;
    cin >> n;
    dp[1]=dp[2]=1;
    for(int i=3; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
    //원리는 피보나치 수와 같으나, 출력값이 int범위를 넘는다
    cout << dp[n];
    return 0;
}
