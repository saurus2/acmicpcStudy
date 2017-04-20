#include <iostream>
using namespace std;
int main(){
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    cout << min(abs(x-0),min(abs(x-w),min(abs(y-0),abs(y-h))));
    return 0;
}
