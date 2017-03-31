#include <iostream>
#include <string.h>
#include <memory.h>
#include <stdio.h>

using namespace std;
int main(){
    int t,n,m,dp[10001]={0},coin[21]={0};
    cin >> t;
    for(int i=0; i<t; i++){
        memset(dp,0,sizeof(dp));
        //dp 배열 초기화
        memset(coin,0,sizeof(coin));
        //입력받는 코인 종류 초기화
        cin >> n;
        //코인 갯수 입력
        for(int k=0; k<n; k++){
            cin >> coin[k];
            //코인 종류들 입력
        }
        cin >> m;
        dp[0]=1;
        //dp[b] = dp[b] + dp[b - coin[a]];
        //위의 식대로 계산시 dp[2] = dp[2] + dp[0]; 일때 해당 코인 1개는 무조건 저장해야 함
        for(int a=0; a<n; a++){
            for(int b=coin[a]; b<=m; b++){
                dp[b] = dp[b] + dp[b - coin[a]];
                //코인을 사용해서 저장한 횟수를 축적하여 사용함
                //2원 사용시 4원을 만든다면 2원을 만든 1번과
                //4원 사용시 4원 한개와 2원 만들때 축적된 코인 갯수 사용
                //dp[2] = dp[2] + dp[0];
                //dp[4] = dp[4] + dp[2];
                //4원 일때 dp[4] = dp[4] + dp[0];
            }
        }
        cout << dp[m] << endl;
    }
    return 0;
}
