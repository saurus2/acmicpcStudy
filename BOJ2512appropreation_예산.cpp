#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ar[10001]={0}, n, lo, hi, sm,m,mid,r;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ar[i];
        sm += ar[i];
    }
    sort(ar,ar+n,greater<int>());
    cin >> m;
    if(sm<=m){
        cout << ar[0];
        return 0;
    }
    else{
        lo = 0; hi = 100001;
        while(lo<hi){
            mid = (lo + hi) >> 1;
            r = 0;
            for(int i=0; i<n; i++){
                if(mid >= ar[i])
                    r+= ar[i];
                else
                    r+= mid;
            }
            if(r<=m)
                lo = mid + 1;
            else
                hi = mid;
        }
        cout << lo-1;
    }
    return 0;
}
