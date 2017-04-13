#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int n;
int w[20][20];
int dp[20][1<<17];

int tsp(int node, int visited){
    if(visited == ((1<<n)-1)){
        //전부 방문한 경우
        if(w[node][1] != 0)
            return w[node][1];
    }
    int &ret = dp[node][visited];
    if(ret != 0) return ret;
    ret = 20000000;
    for(int i=1; i<=n; i++){
        if(!(visited & (1<<(i-1))) && w[node][i] != 0){
            //방문 되었는지 확인 && 노드에서 i로 갈수있는지 확인
            ret = min(ret, w[node][i] + tsp(i, visited | (1<<(i-1))));
            //원래 값하고 i통해서 갈수있는곳 비교
        }
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&w[i][j]);
    printf("%d\n",tsp(1,1));
    return 0;
}
