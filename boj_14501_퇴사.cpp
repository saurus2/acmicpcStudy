#include <iostream>
using namespace std;
int N,ar[16][2],maxV=-999999999,sum = 0;
int visited[16]={0,};

void dfs(int idx){
    if(idx >= N){
        if(maxV < sum){
            maxV = sum;
        }
        return;
    }
    if(idx + ar[idx][0] <= N){
        sum += ar[idx][1];
        dfs(idx + ar[idx][0]);
        sum -= ar[idx][1];
    }
    dfs(idx + 1);
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> ar[i][0] >> ar[i][1];
    dfs(0);
    cout << maxV << endl;
}
