#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n = 1, ar[14]={0},ch[14]={0},cnt=0;
void dfs(int k,int ct){
    if(k>n) return;
    if(ct>=6){
        int end = 0;
        while(end<n){ //체크된 6개의 숫자를 출력함
            if(ch[end]==1) cout << ar[end] << " ";
            end++;
        }
        cout << endl;
        return;
    }
    if(ch[k]!=1){
        ch[k]=1;//선택된 숫자 위치의 배열의 인덱스를 체크
        dfs(k+1,ct+1);//6개의 번호를 계속 체크하며 인덱스를 늘려줌
    }
    ch[k]=0;//마지막 체크를 풀고 다음 칸으로 건너 뛰어 dfs 수행
    dfs(k+1,ct);
    return;
}
int main(){
    while(n!=0){
        cin >> n;
        memset(ch,0,n);//배열 초기화
        memset(ar,0,14);
        for(int i=0; i<n; i++){
            cin >> ar[i];
        }
        sort(ar, ar+n);
        dfs(0,cnt);//0,0 부터 dfs 시작
        cout << endl;
    }
    return 0;
}
