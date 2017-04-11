#include <iostream>
using namespace std;
int dp[1001]={0};
int main(){
    int n;
    cin >> n;
    dp[1]=1; dp[2]=2;
    for(int i=3; i<=n; i++) dp[i] = (dp[i-1] + dp[i-2])%10007;
    //1개랑 2개는 따로 저장
    //타일을 하니씩 추가했을때 이전의 타일모양들의 합과 경우의 수가 같은 규칙이 있음
    cout << dp[n];
    return 0;
}
