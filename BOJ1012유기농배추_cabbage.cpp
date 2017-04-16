#include <iostream>
#include <memory.h>
using namespace std;
bool mat[50][50] = {0};
int n,m,k,i,j,y,x,t,cnt;

void dfs(int i, int j){
    mat[i][j] = 0;
    //갔던 곳은 탐색하지 않음
    if( i && mat[i-1][j] ) dfs(i-1, j);
    if(i != n-1 && mat[i+1][j]) dfs(i+1,j);
    if(j && mat[i][j-1]) dfs(i, j-1);
    if(j!=m-1 && mat[i][j+1]) dfs(i,j+1);
    //죄우 상하로 dfs 탐색함 갔던곳은 0으로 줄임
    return;
}

int main(){
    cin >> t;
    while(t--){
        memset(mat, 0, 2500);
        cin >> m >> n >> k;
        for(cnt = i = 0; i<k; i++){
            cin >> x >> y;
            mat[y][x] = 1;
            //배추의 위치만 1로 저장
        }
        for(i = 0; i<n; i++){
            for(j=0; j<m; j++){
                if(mat[i][j]){
                    cnt++;
                    //dfs가 끝날때마다 cnt 추가
                    dfs(i,j);
                }
            }
        }
        cout << cnt << endl;
    }
}
