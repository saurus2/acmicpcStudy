#include <iostream>
using namespace std;
int main(){
    int n,w,h;
    cin >> n >> w >> h;
    while(n--){
        int tmp;
        cin >> tmp;
        cout << ( tmp <= w || tmp <= h || tmp*tmp <= (w*w + h*h) ? "DA" : "NE") << endl;
    }
    return 0;
}
