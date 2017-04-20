#include <iostream>
using namespace std;
int main(){
    int l,a,b,c,d;
    cin >> l >> a >> b >> c >> d;
    cout << l - max((a%c == 0 ? a/c : a/c + 1), (b%d == 0 ? b/d : b/d + 1));
    return 0;
}
