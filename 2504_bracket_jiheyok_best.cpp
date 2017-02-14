#include <iostream>
#include <stack>
using namespace std;

int b[35] = {0};
char ch[35] = {0};
stack<char> a;

void check(int n){
    int k = a.size();
    if(b[k] == 0) b[k] = 1;//닫히는 괄호에 따라 곱하기 해줄때 1에 2혹은 3을 곱함
    b[k-1] += b[k] * n;//곱해서 전의 배열 자리에 값을 더해줌
    a.pop();
    b[k] = 0;//더하는 값이 처리되면 0으로 바꿈
}

int main(){
    cin >> ch;
    for(int i=0; ch[i]; i++){
        if(ch[i] == '(' || ch[i] == '[') a.push(ch[i]);//여는 괄호를 스택에 넣기
        else if(ch[i] == ')' && a.top() == '(') check(2);//닫는 괄호를 구분함
        else if(ch[i] == ']' && a.top() == '[') check(3);
        else {cout << "0"; return 0;}
    }
    cout << b[0];
    return 0;
}
