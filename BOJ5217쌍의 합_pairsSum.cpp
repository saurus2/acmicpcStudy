#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int tmp;
        cin >> tmp;
        cout << "Pairs for " << tmp << ": ";
        for(int i=1; i<tmp; i++){
            if(i>1 && i<(tmp+1)/2) cout << ", ";
            if((tmp+1)/2 == i|| tmp-i == i) break;
            cout << i << " " << tmp - i;
        }
        cout << endl;
    }
    return 0;
}
