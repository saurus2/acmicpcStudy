#include <iostream>
using namespace std;
int n,mp[15][2],answer;
void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> mp[i][0] >> mp[i][1];
    }
    answer=-1;
}
void dfs(int idx,int sum){
    if(idx>=n){
        if(answer<sum)
            answer=sum;
        return;
    }
    
    if(idx+mp[idx][0]<=n){
        sum+=mp[idx][1];
        dfs(idx+mp[idx][0],sum);
        sum-=mp[idx][1];
    }
    dfs(idx+1,sum);
}
int main(){
    input();
    for(int i=0; i<n; i++){
        dfs(i,0);
    }
    cout << answer << endl;
    return 0;
}

