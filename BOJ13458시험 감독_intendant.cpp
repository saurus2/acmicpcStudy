#include <iostream>
using namespace std;
int main(){
    long long n,a[1000001]={0},b,c,cnt=0;
    //시험장, 응시자수, 한방 총감독 감시수, 부감독 한방 감시수
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> b >> c;
    for(int i=0; i<n; i++){
        cnt++;
        a[i] -= b;
    }
    for(int i=0; i<n; i++){
        if(a[i] > 0 && a[i] > c){
            if(a[i] % c == 0) cnt += a[i]/c;
            else cnt += a[i]/c + 1;
        }else if(a[i] > 0){
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}

