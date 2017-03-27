#include <iostream>
#include <memory.h>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define endp 999999999
using namespace std;
int main(){
    int narr[100001]={0};
    int t,n,s,ret,cnt;
    cin >> t;
    for(int i=1; i<=t; i++){
        memset(narr,0,sizeof(narr));
        ret=0;
        cin >> n >> s;
        cnt = n+1;
        for(int j=0; j<n; j++){
            cin >> narr[j];
        }
        int k,p;
        for(k=p=0; k<n; k++){
            ret += narr[k];
            if(ret>=s){
                for(; p<=k; p++){
                    if(ret - narr[p] >= s)
                        ret -= narr[p];
                    else break;
                }
                cnt = min(cnt,k-p+1);
            }
        }
        cout << "#testcase" << i << endl;
        printf("%d\n",cnt==n+1?0:cnt);
    }
    return 0;
}
