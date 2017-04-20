#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        char a1[101],b1[101];
        int cnt=0,i=0;
        cin >> a1 >> b1;
        cout << "Hamming distance is ";
        while(a1[i]!='\0'){
            if(a1[i] ^ b1[i]) cnt++;
            i++;
        }
        cout << cnt << "." << endl;
    }
    return 0;
}
