#include <iostream>
#include <deque>
using namespace std;
int N,op[4],minV = 1000000000, maxV = -1000000000;
deque <int> ar;
void dfs(int idx,int op_idx,int val){
    if(idx >= N){
        if(minV > val)
            minV = val;
        if(maxV < val)
            maxV = val;
        return;
    }
    
    if(op[op_idx] == 0){
        return;
    }
    
    op[op_idx]--;
    
    if(op_idx == 0){
        val += ar[idx];
        for(int i=0; i<4; i++)
            dfs(idx+1,i,val);
        val -= ar[idx];
        op[op_idx]++;
    }
    if(op_idx == 1){
        val -= ar[idx];
        for(int i=0; i<4; i++)
            dfs(idx+1,i,val);
        val += ar[idx];
        op[op_idx]++;
    }
    if(op_idx == 2){
        val *= ar[idx];
        for(int i=0; i<4; i++)
            dfs(idx+1,i,val);
        val /= ar[idx];
        op[op_idx]++;
    }
    if(op_idx == 3){
        val /= ar[idx];
        for(int i=0; i<4; i++)
            dfs(idx+1,i,val);
        val *= ar[idx];
        op[op_idx]++;
    }
    return;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        ar.push_back(tmp);
    }
    for(int i=0; i<4; i++){
        cin >> op[i];
    }
    for(int i=0; i<4; i++)
        dfs(1,i,ar[0]);
    
    cout << maxV << endl << minV << endl;
    
    return 0;
}

