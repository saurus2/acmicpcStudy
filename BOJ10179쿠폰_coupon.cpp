#include <iostream>
using namespace std;
int main(){
    int n;
    double ret;
    cin >> n;
    while(n--){
        cin >> ret;
        ret *= 0.8;
        cout << fixed;
        cout.precision(2);
        cout << "$" << ret << endl;
    }
    return 0;
}
