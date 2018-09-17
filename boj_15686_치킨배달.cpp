#include <iostream>

using namespace std;

int N,M,minV,cnt,cnt2;
int mp[51][51];
int ck[101] = {0,};
int building[101][2];
int start[101][2];
void dfs(int idx, int build){
    if(idx > cnt2){
        return;
    }
    if(build == M){
        int minSum = 0;
        int minValue;
        for(int i=0; i<cnt; i++){
            minValue = 999999999;
            for(int j=0; j<cnt2; j++){
                if(ck[j] == 1){
                    int des = abs(start[i][0] - building[j][0]) + abs(start[i][1] - building[j][1]);
                    if(minValue > des)
                        minValue = des;
                }
            }
            minSum += minValue;
        }
        if(minV > minSum){
            minV = minSum;
        }
        return;
    }
        if(ck[idx] == 0){
            ck[idx] = 1;
            dfs(idx+1,build+1);
        }
        ck[idx] = 0;
        dfs(idx+1,build);
    
    return;
}

int main(){
    minV = 999999999;
    cin >> N >> M;
    cnt = 0;
    cnt2 = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> mp[i][j];
            if(mp[i][j] == 1){
                start[cnt][0] = i;
                start[cnt++][1] = j;
            }
            if(mp[i][j] == 2){
                building[cnt2][0] = i;
                building[cnt2++][1] = j;
            }
        }
    }
    dfs(0,0);
    cout << minV;
    return 0;
}

