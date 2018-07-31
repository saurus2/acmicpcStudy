#include <iostream>
using namespace std;

int T,N,B,ans;
int ar[21];
int ch[21];

void dfs(int idx,int sum){
    if(ch[idx] == 1)
        return;
    if(sum >= B){
        if(sum < ans){
            ans = sum;
            return;
        }
    }
    if(idx >= N)
        return;
    ch[idx] = 1;
    dfs(idx+1,sum+ar[idx]);
    ch[idx] = 0;
    dfs(idx+1,sum);
}

int main(){
    cin >> T;
    for(int i=1; i<=T ;i++){
        for(int j=0; j<21; j++){
            ar[j] = 0;
            ch[j] = 0;
        }
        ans = 10000 * 21;
        cin >> N >> B;
        for(int j=0; j<N; j++)
            cin >> ar[j];
        dfs(0,0);
        cout << "#" << i << " " << ((ans > B) ? ans - B : B - ans) << endl;
    }
}

