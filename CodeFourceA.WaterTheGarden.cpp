#include <cstdio>
#include <deque>
#include <memory.h>
using namespace std;
deque <int> que;
int t,n,k,curTime, curWater;
int ar[201] = {0,};
int main(){
    scanf("%d", &t);
    for(int tc = 1; tc<=t; tc++){
        curTime = 1;
        memset(ar,0,sizeof(ar));
        que.clear();
        scanf("%d %d", &n, &k);
        curWater = 0;
        for(int i=0; i<k; i++){
            int tab;
            scanf("%d", &tab);
            if(ar[tab] == 1) continue;
            curWater++;
            ar[tab] = 1;
            que.push_back(tab);
        }
        if(curWater == n){
            printf("%d\n", curTime);
            continue;
        }
        int queSize;
        while(curWater != n){
            curTime++;
            queSize = (int)que.size();
            for(int i=0; i<queSize; i++){
                int curIdx = que.front();
                que.pop_front();
                int flag = 0;
                int nextRIdx, nextLIdx;
                nextRIdx = curIdx + curTime - 1;
                nextLIdx = curIdx - curTime + 1;
                if(nextRIdx > 0 && nextRIdx <= n){
                    if(ar[nextRIdx] == 1) continue;
                    ar[nextRIdx] = 1;
                    curWater++;
                    if(curWater == n) break;
                    flag = 1;
                }
                if(nextLIdx > 0 && nextLIdx <= n){
                    if(ar[nextLIdx] == 1) continue;
                    ar[nextLIdx] = 1;
                    curWater++;
                    if(curWater == n) break;
                    flag = 1;
                }
                if(curWater == n) break;
                if(flag == 1)
                    que.push_back(curIdx);
            }
        }
        printf("%d\n", curTime);
    }
}

