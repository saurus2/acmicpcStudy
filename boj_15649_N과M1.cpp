#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

int ar[9] = {0,};
int M,N,cnt = 0;
vector <int> li;

void dfs(){
    if(cnt == N){
        for(int i = 0; i<(int)li.size(); i++){
            printf("%d ", li.at(i));
        }
        printf("\n");
        return;
    }
    
    for(int i=0; i<M; i++){
        if(ar[i] == 1) continue;
        ar[i] = 1;
        li.push_back(i+1);
        cnt++;
        dfs();
        ar[i] = 0;
        li.pop_back();
        cnt--;
    }
}

int main(){
    cnt = 0;
    memset(ar,0,sizeof(ar));
    li.clear();
    cin >> M >> N;
    dfs();
}


