#include <iostream>
using namespace std;
int main(){
    double no,tmp=-99;
    while(1){
        cin >> no;
        if(no == 999) break;
        if(tmp != -99){
            cout.precision(2);
            cout << fixed;
            cout << no - tmp << endl;
        }
        tmp = no;
    }
    return 0;
}
