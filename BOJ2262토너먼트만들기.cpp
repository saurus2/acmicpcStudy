#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <cmath>
#define INF 987654321;
using namespace std;
int n, a[257], m[257][257], dp[257][257];
int func(int lo, int hi){
    int &ret = dp[lo][hi];
    if(ret != -1) return ret;
    if(lo == hi) return ret = 0;
    ret = INF;
    for (int i= lo; i<hi; i++){
        ret = min(ret, func(lo,i) + func(i+1,hi) + abs(m[i+1][hi] - m[lo][i]));
        //그룹내에 랭킹차가 가장 적은것을 돌려준다
        //시작부터 끝 배열에서 시작하며 전체 배열을 돌려가며 확인
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    memset(m, 0x3f, sizeof(m));
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<= n; i++){
        for(int j=i; j<=n; j++){
            if(i==j) m[i][j] = a[i];
            //구간에 비교될 대상 저장
            else
                m[i][j] = min(m[i][j-1], a[j]);
            //구간에 가장 높은 랭킹을 저장
        }
    }
    printf("%d\n", func(1,n));
    return 0;
}
