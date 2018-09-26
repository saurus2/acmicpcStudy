#include <iostream>
using namespace std;
int N;
int mp[21][21];
int ck[21];
int ans = 999999999;


void dfs(int idx, int cnt){
    if(idx >= N)
        return;
    if(cnt == N/2){
        int sumA = 0, sumB = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(i!=j && ck[i] == 1 && ck[j] == 1){
                    sumA += mp[i][j];
                }else if(i!=j && ck[i] == 0 && ck[j] == 0){
                    sumB += mp[i][j];
                }
            }
        }
        if(ans > abs(sumA - sumB)){
            ans = abs(sumA - sumB);
        }
        return;
    }
    
    ck[idx] = 1;
    dfs(idx+1,cnt+1);
    ck[idx] = 0;
    dfs(idx+1,cnt);
}


int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> mp[i][j];
        }
        ck[i] = 0;
    }
    dfs(0,0);
    cout << ans;
    return 0;
}

