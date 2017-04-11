#include <iostream>
using namespace std;
int dp[1001]={0},li[1001]={0};
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> li[i];
    //붕어빵 갯수당 얼마인지 입력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i<=j){
                //j의 갯수 붕어빵을 팔았을때
                //이전 붕어빵판것과 같이 팔 붕어빵의 가격을 더해 비교하여 큰 것을 저장
                dp[j] = dp[j] > dp[j-i] + li[i] ?
                //j갯수의 붕아빵 팔때 i붕어빵을 팔수있는 갯수가 남아있어야함
                dp[j] : dp[j-i] + li[i];
                //팔고남은 j갯수에 j-i 만큼의 붕어빵을 더 파는게 이득이라면 갱신
            }
        }
    }
    cout << dp[n];
    return 0;
}
