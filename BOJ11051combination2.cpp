#include <iostream>
using namespace std;
int main(){
    int a,b,dp[1001][1001];
    cin >> a >> b;
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2; i<=a; i++){
        for(int j=0; j<=b; j++){
            if(i==0 || j==i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            //nCk = nCk-1 + nCk 식을 이용해 , 파스칼삼각형을 이용해 dp로 이항계수를 구한다
            //여기서 dp 로 O(nk) 말고 역원을 이용해 O(logn)으로 풀수도 있다
            dp[i][j] %= 10007;
        }
    }
    cout << dp[a][b];
    return 0;
}
