#include <stack>
#include <iostream>
using namespace std;
int main(){
    int cnt = 0,scnt=0,rcnt=0,op=0;
    stack <char> steel;
    char n[1000001] = {0,};
    cin >> n;
    while(n[cnt]!=0) steel.push(n[cnt++]);
    while(!steel.empty()){
        if(steel.top() == ')'){
            scnt++;
            op=1;
            steel.pop();
        }else if(steel.top() == '('){
            scnt--;
            if(op==1) rcnt+=scnt;
            else rcnt++;
            op=0;
            steel.pop();
        }
    }
    cout << rcnt;
    return 0;
}
