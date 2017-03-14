#include <iostream>
#include <algorithm>
#include <cstring>
#include <memory.h>
using namespace std;
int n,a[50],dp[50][500001];

int dy(int p, int dif){
    if(p==n && dif == 0) //양 옆의 탑의 높이 차가 0일때
        //옮긴 블럭 수와 블럭의 갯수 같을때
        return 0;
    else if(p==n && dif != 0)
        //옮긴 블럭 수 같을때
        //블럭의 크기가 차이가 나면 최소값 리턴
        return -1e9;
    int &ret = dp[p][abs(dif)];
        //dp배열에 저장된 블럭 갯수와 블럭 차이 갯수에 저장된 것 리드
    if(ret!=-1)
        return ret;
    ret = 0;
        //초기화
    
    ret = dy(p+1, dif);
    //옮긴 블럭 갯수 늘리고 차이 입력
    ret = max(ret, dy(p+1, dif + a[p]) + a[p]);
    //블럭 높이와 다음 인댁스의 블럭 추가 및 제거
    ret = max(ret, dy(p+1, dif - a[p]) + a[p]);
    return ret;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    memset(dp,-1,sizeof(dp));
    int ret = dy(0,0);
    if(ret<=0) cout << "-1";
    else cout << ret/2;
}
