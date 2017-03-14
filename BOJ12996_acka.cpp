#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
long long peo[51][51][51][51];
long long mod = 1000000007;

long long dp(long long n,long long d, long long k, long long h){
    if(d + k + h < n)
        //총 노래 수 보다 가수들이 불러야 하는 노래가 적을때
        return 0;
    if(d<0 || k<0 || h<0 || n<0)
        //노래 수, 가수 들이 불러야할 곡 수가 0보다 작을때
        return 0;
    if(n == 0){
        //곡 수가 0일때
        if(d == 0 && k == 0 && h == 0){
            // 각 가수가 곡 조건을 다 채웠을때
            return 1;
        }
        return 0;
    }
    
    if(peo[n][d][k][h] != -1)
        //dp 배열에 접근 했었다면, 그 값 리턴
        return peo[n][d][k][h];
    
    return peo[n][d][k][h] = (dp(n-1,d-1,k,h) + dp(n-1,d,k-1,h) + dp(n-1,d,k,h-1) + dp(n-1,d-1,k-1,h) + dp(n-1,d-1,k,h-1) + dp(n-1,d,k-1,h-1) + dp(n-1,d-1,k-1,h-1))%mod;
    //7가지의 종류, 1개 , 2개, 3개 곡을 불렀을때의 경우로 재귀함수 !
}

int main(){
    long long n,d,k,h;
    memset(peo,-1,sizeof(peo));
    cin >> n >> d >> k >> h;
    cout << dp(n,d,k,h)%mod << endl;
    return 0;
}
