#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack <char> bracket;
    char n[2001]={0,};
    int cnt = 0, re = 0, no = 1;
    while(1){
        cin >> n;
        if(n[0] == '-') break;
        for(int i=0; i<2001; i++){
            if(n[i] == '\0') break;
            if(cnt == 0){
                bracket.push(n[i]);
                cnt++;
            }else {
                if(n[i] == '}' && bracket.top() == '{'){
                    cnt--;
                    bracket.pop();
                }else{
                    cnt++;
                    bracket.push(n[i]);
                }
            }
        }
        cnt = 0, re = 0;
        while(!bracket.empty()){
            if(bracket.top() == '{' && cnt == 0) { re++; cnt++; bracket.pop(); }
            else if(cnt > 0 && bracket.top() == '{') { cnt--; bracket.pop(); }
            else if(bracket.top() == '}' && cnt == 0) { cnt++; bracket.pop(); }
            else if(bracket.top() == '}' && cnt > 0) { cnt--; re++; bracket.pop();}
        }
        cout << no++ << ". ";
        cout << re << endl;
    }
    return 0;
}
