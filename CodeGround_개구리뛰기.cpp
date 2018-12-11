#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
#include <vector>
using namespace std;
typedef pair < int , int > pii;
int T,K,N,des,visited[1000001];
vector <int> vc;
queue <pii> que;

void tmp(int tc){
    int end = (int)vc.size()-1;
    int ccnt = 0;
    int cidx = end-1;
    
    while(1){
        bool f=false;
        for(int i=cidx; i>=0; i--){
            if((vc.at(end) - K) <= vc.at(i)){
                cidx = i;
                f=true;
            }else{
                break;
            }
        }
        if(f==true){
            ccnt++;
            end = cidx;
            if(vc.at(cidx) - K <= 0){
                ccnt++;
                printf("Case #%d\n%d\n",tc,ccnt);
                return;
            }
            cidx = cidx - 1;
        }else{
            break;
        }
    }
    printf("Case #%d\n-1\n",tc);
    return;
}

int main(){
    scanf("%d", &T);
    for(int tc=1; tc<=T; tc++){
        vc.clear();
        scanf("%d", &N);
        int dol=0;
        for(int i=0; i<N; i++){
            scanf("%d", &dol);
            vc.push_back(dol);
        }
        scanf("%d", &K);
        tmp(tc);
    }
    return 0;
}

