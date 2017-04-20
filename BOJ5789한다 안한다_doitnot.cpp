#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
int main(){
    int t;
    cin >> t;
    string s;
    while(t--){
        s.clear();
        cin >> s;
        if(s[s.size()/2-1] == s[s.size()/2])
            cout << "Do-it" << endl;
        else
            cout << "Do-it-Not" << endl;
    }
    return 0;
}
