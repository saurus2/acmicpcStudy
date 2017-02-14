#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n=0,a[51]={0,},b[51]={0,},max=-1,bt[51]={0,},re=0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    sort(a,a+n);
    for(int i=0; i<n; i++) {
        int idx=0;
        max = -1;
        for(int j=0; j<n; j++){
            if(max<b[j] && bt[j] != 1) {
                max=b[j];
                idx = j;
            }
        }
        bt[idx]=1;
        re+=b[idx] * a[i];
    }
    cout << re;
}
