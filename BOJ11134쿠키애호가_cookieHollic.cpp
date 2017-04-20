#include <iostream>
using namespace std;
int main(){
    int t,n,c;
    cin >> t;
    while(t--){
        cin >> n >> c;
        if(n%c == 0)
            cout << n/c << endl;
        else
            cout << n/c+1 << endl;
    }
    return 0;
}
